import os
import sys

graphviz_path = r"C:\Program Files\Graphviz\bin"
os.environ["PATH"] += os.pathsep + graphviz_path
import random
import heapq
import pandas as pd
from graphviz import Digraph

class Node:
    def __init__(self, freq, symbol, left=None, right=None):
        self.freq = freq
        self.symbol = symbol
        self.left = left
        self.right = right
        self.huff = ''

    def __lt__(self, other):
        return self.freq < other.freq

def calculateHuffmanCode(node, val='', huffman_codes={}):
    newVal = val + str(node.huff)
    if node.left:
        calculateHuffmanCode(node.left, newVal, huffman_codes)
    if node.right:
        calculateHuffmanCode(node.right, newVal, huffman_codes)
    if not node.left and not node.right:
        huffman_codes[node.symbol] = newVal
    return huffman_codes

def displayHuffmanTable(symbols, frequencies, huffman_codes):
    table_data = []
    total_bits = 0
    for symbol, freq in zip(symbols, frequencies):
        code = huffman_codes[symbol]
        bits = len(code)
        total = bits * freq
        table_data.append([symbol, freq, code, bits, total])
        total_bits += total
    df = pd.DataFrame(table_data, columns=["Symbol/Letter", "Frequency", "Huffman Code", "Bits", "Total"])
    print(df.to_string(index=False))
    print(f"\nTotal bits used for encoding: {total_bits}")

def visualizeTree(node, graph, code=''):
    if node.left:
        graph.node(str(id(node.left)), f"{node.left.symbol} ({node.left.freq})")
        graph.edge(str(id(node)), str(id(node.left)), label='0')
        visualizeTree(node.left, graph, code + '0')
    if node.right:
        graph.node(str(id(node.right)), f"{node.right.symbol} ({node.right.freq})")
        graph.edge(str(id(node)), str(id(node.right)), label='1')
        visualizeTree(node.right, graph, code + '1')

def createHuffmanTree():
    n = int(input("Enter the number of symbols: "))
    symbols = []
    frequencies = []
    for i in range(n):
        symbol = input(f"Enter symbol {i+1}: ")
        frequency = int(input(f"Enter frequency of '{symbol}': "))
        symbols.append(symbol)
        frequencies.append(frequency)


    nodes = [Node(frequencies[i], symbols[i]) for i in range(n)]
    nodes.sort(key=lambda x: x.symbol)  
    heapq.heapify(nodes)

    while len(nodes) > 1:
        nodes.sort(key=lambda x: x.freq)

        if len(nodes) >= 2:
            left = random.choice(nodes[:2]) 
            nodes.remove(left)
            right = random.choice(nodes[:2])  
            nodes.remove(right)

            left.huff = 0
            right.huff = 1
            
            newNode = Node(left.freq + right.freq, left.symbol + right.symbol, left, right)
            heapq.heappush(nodes, newNode)
        else:
            break

    root = nodes[0]
    huffman_codes = calculateHuffmanCode(root)
    displayHuffmanTable(symbols, frequencies, huffman_codes)

    graph = Digraph(comment='Huffman Tree')
    graph.node(str(id(root)), f"{root.symbol} ({root.freq})")
    visualizeTree(root, graph)

    graph.render("huffman_tree", format="png", cleanup=True)

    import os
    os.startfile("huffman_tree.png")

    print("\nHuffman tree diagram saved and opened as 'huffman_tree.png'")

createHuffmanTree()
