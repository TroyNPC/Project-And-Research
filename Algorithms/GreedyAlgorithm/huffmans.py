import os
import heapq
import pandas as pd
from graphviz import Digraph

graphviz_path = r"C:\Program Files\Graphviz\bin"
os.environ["PATH"] += os.pathsep + graphviz_path

class Node:
    def __init__(self, freq, symbol, left=None, right=None):
        self.freq = freq
        self.symbol = symbol
        self.left = left
        self.right = right
        self.huff = ''

    def __lt__(self, other):
        return self.freq < other.freq

def calculate_huffman_code(node, val='', huffman_codes={}):
    new_val = val + str(node.huff)
    if node.left:
        calculate_huffman_code(node.left, new_val, huffman_codes)
    if node.right:
        calculate_huffman_code(node.right, new_val, huffman_codes)
    if not node.left and not node.right:
        huffman_codes[node.symbol] = new_val
    return huffman_codes

def display_huffman_table(symbols, frequencies, huffman_codes):
    table_data = []
    total_bits = 0
    for symbol, freq in zip(symbols, frequencies):
        code = huffman_codes[symbol]
        bits = len(code)
        total = bits * freq
        table_data.append([symbol, freq, code, bits, total])
        total_bits += total
    df = pd.DataFrame(table_data, columns=["Symbol", "Frequency", "Huffman Code", "Bits", "Total Bits"])
    print(df.to_string(index=False))
    print(f"\nTotal bits used for encoding: {total_bits}")

def visualize_tree(node, graph, code=''):
    if node.left:
        graph.node(str(id(node.left)), f"{node.left.symbol} ({node.left.freq})")
        graph.edge(str(id(node)), str(id(node.left)), label='0')
        visualize_tree(node.left, graph, code + '0')
    if node.right:
        graph.node(str(id(node.right)), f"{node.right.symbol} ({node.right.freq})")
        graph.edge(str(id(node)), str(id(node.right)), label='1')
        visualize_tree(node.right, graph, code + '1')

def create_huffman_tree():
    n = int(input("Enter the number of symbols: "))
    symbols, frequencies = [], []
    for i in range(n):
        symbol = input(f"Enter symbol {i + 1}: ")
        frequency = int(input(f"Enter frequency of '{symbol}': "))
        symbols.append(symbol)
        frequencies.append(frequency)

    nodes = [Node(frequencies[i], symbols[i]) for i in range(n)]
    heapq.heapify(nodes)

    while len(nodes) > 1:
        left = heapq.heappop(nodes)
        right = heapq.heappop(nodes)
        left.huff, right.huff = 0, 1
        newNode = Node(left.freq + right.freq, left.symbol + right.symbol, left, right)
        heapq.heappush(nodes, newNode)

    root = nodes[0]
    huffman_codes = calculate_huffman_code(root)
    display_huffman_table(symbols, frequencies, huffman_codes)

    graph = Digraph(comment='Huffman Tree')
    graph.node(str(id(root)), f"{root.symbol} ({root.freq})")
    visualize_tree(root, graph)
    graph.render("huffman_tree", format="png", cleanup=True)
    os.startfile("huffman_tree.png")
    print("\nHuffman tree diagram saved and opened as 'huffman_tree.png'")

create_huffman_tree()
