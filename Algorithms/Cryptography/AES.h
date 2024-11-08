const int Nb = 4; 
const int Nk = 4; 
const int Nr = 1; 

typedef vector<vector<unsigned char>> State;

const unsigned char s_box[256] = {
    0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
    0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
    0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
    0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
    0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
    0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
    0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
    0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
    0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
    0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
    0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
    0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
    0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
    0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
    0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
    0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16
};

const unsigned char inv_s_box[256] = {
    0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB,
    0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB,
    0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E,
    0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25,
    0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92,
    0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA, 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84,
    0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06,
    0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02, 0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B,
    0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA, 0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73,
    0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85, 0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E,
    0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89, 0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B,
    0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20, 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4,
    0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F,
    0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D, 0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF,
    0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0, 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D
};

const unsigned char mul2[256] = {
    0x00, 0x02, 0x04, 0x06, 0x08, 0x0A, 0x0C, 0x0E, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1A, 0x1C, 0x1E,
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2A, 0x2C, 0x2E, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3A, 0x3C, 0x3E,
    0x40, 0x42, 0x44, 0x46, 0x48, 0x4A, 0x4C, 0x4E, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5A, 0x5C, 0x5E,
    0x60, 0x62, 0x64, 0x66, 0x68, 0x6A, 0x6C, 0x6E, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7A, 0x7C, 0x7E,
    0x80, 0x82, 0x84, 0x86, 0x88, 0x8A, 0x8C, 0x8E, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9A, 0x9C, 0x9E,
    0xA0, 0xA2, 0xA4, 0xA6, 0xA8, 0xAA, 0xAC, 0xAE, 0xB0, 0xB2, 0xB4, 0xB6, 0xB8, 0xBA, 0xBC, 0xBE,
    0xC0, 0xC2, 0xC4, 0xC6, 0xC8, 0xCA, 0xCC, 0xCE, 0xD0, 0xD2, 0xD4, 0xD6, 0xD8, 0xDA, 0xDC, 0xDE,
    0xE0, 0xE2, 0xE4, 0xE6, 0xE8, 0xEA, 0xEC, 0xEE, 0xF0, 0xF2, 0xF4, 0xF6, 0xF8, 0xFA, 0xFC, 0xFE,
    0x1B, 0x19, 0x1F, 0x1D, 0x13, 0x11, 0x17, 0x15, 0x0B, 0x09, 0x0F, 0x0D, 0x03, 0x01, 0x07, 0x05,
    0x3B, 0x39, 0x3F, 0x3D, 0x33, 0x31, 0x37, 0x35, 0x2B, 0x29, 0x2F, 0x2D, 0x23, 0x21, 0x27, 0x25,
    0x5B, 0x59, 0x5F, 0x5D, 0x53, 0x51, 0x57, 0x55, 0x4B, 0x49, 0x4F, 0x4D, 0x43, 0x41, 0x47, 0x45,
    0x7B, 0x79, 0x7F, 0x7D, 0x73, 0x71, 0x77, 0x75, 0x6B, 0x69, 0x6F, 0x6D, 0x63, 0x61, 0x67, 0x65,
    0x9B, 0x99, 0x9F, 0x9D, 0x93, 0x91, 0x97, 0x95, 0x8B, 0x89, 0x8F, 0x8D, 0x83, 0x81, 0x87, 0x85,
    0xBB, 0xB9, 0xBF, 0xBD, 0xB3, 0xB1, 0xB7, 0xB5, 0xAB, 0xA9, 0xAF, 0xAD, 0xA3, 0xA1, 0xA7, 0xA5,
    0xDB, 0xD9, 0xDF, 0xDD, 0xD3, 0xD1, 0xD7, 0xD5, 0xCB, 0xC9, 0xCF, 0xCD, 0xC3, 0xC1, 0xC7, 0xC5,
    0xFB, 0xF9, 0xFF, 0xFD, 0xF3, 0xF1, 0xF7, 0xF5, 0xEB, 0xE9, 0xEF, 0xED, 0xE3, 0xE1, 0xE7, 0xE5
};

const unsigned char mul3[256] = {
    0x00, 0x03, 0x06, 0x05, 0x0C, 0x0F, 0x0A, 0x09, 0x18, 0x1B, 0x1E, 0x1D, 0x14, 0x17, 0x12, 0x11,
    0x30, 0x33, 0x36, 0x35, 0x3C, 0x3F, 0x3A, 0x39, 0x28, 0x2B, 0x2E, 0x2D, 0x24, 0x27, 0x22, 0x21,
    0x60, 0x63, 0x66, 0x65, 0x6C, 0x6F, 0x6A, 0x69, 0x78, 0x7B, 0x7E, 0x7D, 0x74, 0x77, 0x72, 0x71,
    0x50, 0x53, 0x56, 0x55, 0x5C, 0x5F, 0x5A, 0x59, 0x48, 0x4B, 0x4E, 0x4D, 0x44, 0x47, 0x42, 0x41,
    0xC0, 0xC3, 0xC6, 0xC5, 0xCC, 0xCF, 0xCA, 0xC9, 0xD8, 0xDB, 0xDE, 0xDD, 0xD4, 0xD7, 0xD2, 0xD1,
    0xF0, 0xF3, 0xF6, 0xF5, 0xFC, 0xFF, 0xFA, 0xF9, 0xE8, 0xEB, 0xEE, 0xED, 0xE4, 0xE7, 0xE2, 0xE1,
    0xA0, 0xA3, 0xA6, 0xA5, 0xAC, 0xAF, 0xAA, 0xA9, 0xB8, 0xBB, 0xBE, 0xBD, 0xB4, 0xB7, 0xB2, 0xB1,
    0x90, 0x93, 0x96, 0x95, 0x9C, 0x9F, 0x9A, 0x99, 0x88, 0x8B, 0x8E, 0x8D, 0x84, 0x87, 0x82, 0x81,
    0x9B, 0x98, 0x9D, 0x9E, 0x97, 0x94, 0x91, 0x92, 0x83, 0x80, 0x85, 0x86, 0x8F, 0x8C, 0x89, 0x8A,
    0xAB, 0xA8, 0xAD, 0xAE, 0xA7, 0xA4, 0xA1, 0xA2, 0xB3, 0xB0, 0xB5, 0xB6, 0xBF, 0xBC, 0xB9, 0xBA,
    0xFB, 0xF8, 0xFD, 0xFE, 0xF7, 0xF4, 0xF1, 0xF2, 0xE3, 0xE0, 0xE5, 0xE6, 0xEF, 0xEC, 0xE9, 0xEA,
    0xCB, 0xC8, 0xCD, 0xCE, 0xC7, 0xC4, 0xC1, 0xC2, 0xD3, 0xD0, 0xD5, 0xD6, 0xDF, 0xDC, 0xD9, 0xDA,
    0x5B, 0x58, 0x5D, 0x5E, 0x57, 0x54, 0x51, 0x52, 0x43, 0x40, 0x45, 0x46, 0x4F, 0x4C, 0x49, 0x4A,
    0x6B, 0x68, 0x6D, 0x6E, 0x67, 0x64, 0x61, 0x62, 0x73, 0x70, 0x75, 0x76, 0x7F, 0x7C, 0x79, 0x7A,
    0x3B, 0x38, 0x3D, 0x3E, 0x37, 0x34, 0x31, 0x32, 0x23, 0x20, 0x25, 0x26, 0x2F, 0x2C, 0x29, 0x2A,
    0x0B, 0x08, 0x0D, 0x0E, 0x07, 0x04, 0x01, 0x02, 0x13, 0x10, 0x15, 0x16, 0x1F, 0x1C, 0x19, 0x1A
};

const unsigned char mul9[256] = {
    0x00, 0x09, 0x12, 0x1B, 0x24, 0x2D, 0x36, 0x3F, 0x48, 0x41, 0x5A, 0x53, 0x6C, 0x65, 0x7E, 0x77,
    0x90, 0x99, 0x82, 0x8B, 0xB4, 0xBD, 0xA6, 0xAF, 0xD8, 0xD1, 0xCA, 0xC3, 0xFC, 0xF5, 0xEE, 0xE7,
    0x3B, 0x32, 0x29, 0x20, 0x1F, 0x16, 0x0D, 0x04, 0x73, 0x7A, 0x61, 0x68, 0x57, 0x5E, 0x45, 0x4C,
    0xAB, 0xA2, 0xB9, 0xB0, 0x8F, 0x86, 0x9D, 0x94, 0xE3, 0xEA, 0xF1, 0xF8, 0xC7, 0xCE, 0xD5, 0xDC,
    0x76, 0x7F, 0x64, 0x6D, 0x52, 0x5B, 0x40, 0x49, 0x3E, 0x37, 0x2C, 0x25, 0x1A, 0x13, 0x08, 0x01,
    0xE6, 0xEF, 0xF4, 0xFD, 0xC2, 0xCB, 0xD0, 0xD9, 0xAE, 0xA7, 0xBC, 0xB5, 0x8A, 0x83, 0x98, 0x91,
    0x4D, 0x44, 0x5F, 0x56, 0x69, 0x60, 0x7B, 0x72, 0x05, 0x0C, 0x17, 0x1E, 0x21, 0x28, 0x33, 0x3A,
    0xDD, 0xD4, 0xCF, 0xC6, 0xF9, 0xF0, 0xEB, 0xE2, 0x95, 0x9C, 0x87, 0x8E, 0xB1, 0xB8, 0xA3, 0xAA,
    0xEC, 0xE5, 0xFE, 0xF7, 0xC8, 0xC1, 0xDA, 0xD3, 0xA4, 0xAD, 0xB6, 0xBF, 0x80, 0x89, 0x92, 0x9B,
    0x7C, 0x75, 0x6E, 0x67, 0x58, 0x51, 0x4A, 0x43, 0x34, 0x3D, 0x26, 0x2F, 0x10, 0x19, 0x02, 0x0B,
    0xD7, 0xDE, 0xC5, 0xCC, 0xF3, 0xFA, 0xE1, 0xE8, 0x9F, 0x96, 0x8D, 0x84, 0xBB, 0xB2, 0xA9, 0xA0,
    0x47, 0x4E, 0x55, 0x5C, 0x63, 0x6A, 0x71, 0x78, 0x0F, 0x06, 0x1D, 0x14, 0x2B, 0x22, 0x39, 0x30,
    0x9A, 0x93, 0x88, 0x81, 0xBE, 0xB7, 0xAC, 0xA5, 0xD2, 0xDB, 0xC0, 0xC9, 0xF6, 0xFF, 0xE4, 0xED,
    0x0A, 0x03, 0x18, 0x11, 0x2E, 0x27, 0x3C, 0x35, 0x42, 0x4B, 0x50, 0x59, 0x66, 0x6F, 0x74, 0x7D,
    0xA1, 0xA8, 0xB3, 0xBA, 0x85, 0x8C, 0x97, 0x9E, 0xE9, 0xE0, 0xFB, 0xF2, 0xCD, 0xC4, 0xDF, 0xD6,
    0x31, 0x38, 0x23, 0x2A, 0x15, 0x1C, 0x07, 0x0E, 0x79, 0x70, 0x6B, 0x62, 0x5D, 0x54, 0x4F, 0x46
};


const unsigned char mul11[256] = {
    0x00, 0x0B, 0x16, 0x1D, 0x2C, 0x27, 0x3A, 0x31, 0x58, 0x53, 0x4E, 0x45, 0x74, 0x7F, 0x62, 0x69,
    0xB0, 0xBB, 0xA6, 0xAD, 0x9C, 0x97, 0x8A, 0x81, 0xE8, 0xE3, 0xFE, 0xF5, 0xC4, 0xCF, 0xD2, 0xD9,
    0x7B, 0x70, 0x6D, 0x66, 0x57, 0x5C, 0x41, 0x4A, 0x23, 0x28, 0x35, 0x3E, 0x0F, 0x04, 0x19, 0x12,
    0xCB, 0xC0, 0xDD, 0xD6, 0xE7, 0xEC, 0xF1, 0xFA, 0x93, 0x98, 0x85, 0x8E, 0xBF, 0xB4, 0xA9, 0xA2,
    0xF6, 0xFD, 0xE0, 0xEB, 0xDA, 0xD1, 0xCC, 0xC7, 0xAE, 0xA5, 0xB8, 0xB3, 0x82, 0x89, 0x94, 0x9F,
    0x46, 0x4D, 0x50, 0x5B, 0x6A, 0x61, 0x7C, 0x77, 0x1E, 0x15, 0x08, 0x03, 0x32, 0x39, 0x24, 0x2F,
    0x8D, 0x86, 0x9B, 0x90, 0xA1, 0xAA, 0xB7, 0xBC, 0xD5, 0xDE, 0xC3, 0xC8, 0xF9, 0xF2, 0xEF, 0xE4,
    0x3D, 0x36, 0x2B, 0x20, 0x11, 0x1A, 0x07, 0x0C, 0x65, 0x6E, 0x73, 0x78, 0x49, 0x42, 0x5F, 0x54,
    0xF7, 0xFC, 0xE1, 0xEA, 0xDB, 0xD0, 0xCD, 0xC6, 0xAF, 0xA4, 0xB9, 0xB2, 0x83, 0x88, 0x95, 0x9E,
    0x47, 0x4C, 0x51, 0x5A, 0x6B, 0x60, 0x7D, 0x76, 0x1F, 0x14, 0x09, 0x02, 0x33, 0x38, 0x25, 0x2E,
    0x8C, 0x87, 0x9A, 0x91, 0xA0, 0xAB, 0xB6, 0xBD, 0xD4, 0xDF, 0xC2, 0xC9, 0xF8, 0xF3, 0xEE, 0xE5,
    0x3C, 0x37, 0x2A, 0x21, 0x10, 0x1B, 0x06, 0x0D, 0x64, 0x6F, 0x72, 0x79, 0x48, 0x43, 0x5E, 0x55,
    0x01, 0x0A, 0x17, 0x1C, 0x2D, 0x26, 0x3B, 0x30, 0x59, 0x52, 0x4F, 0x44, 0x75, 0x7E, 0x63, 0x68,
    0xB1, 0xBA, 0xA7, 0xAC, 0x9D, 0x96, 0x8B, 0x80, 0xE9, 0xE2, 0xFF, 0xF4, 0xC5, 0xCE, 0xD3, 0xD8,
    0x7A, 0x71, 0x6C, 0x67, 0x56, 0x5D, 0x40, 0x4B, 0x22, 0x29, 0x34, 0x3F, 0x0E, 0x05, 0x18, 0x13,
    0xCA, 0xC1, 0xDC, 0xD7, 0xE6, 0xED, 0xF0, 0xFB, 0x92, 0x99, 0x84, 0x8F, 0xBE, 0xB5, 0xA8, 0xA3
};

const unsigned char mul13[256] = {
    0x00, 0x0D, 0x1A, 0x17, 0x34, 0x39, 0x2E, 0x23, 0x68, 0x65, 0x72, 0x7F, 0x5C, 0x51, 0x46, 0x4B,
    0xD0, 0xDD, 0xCA, 0xC7, 0xE4, 0xE9, 0xFE, 0xF3, 0xB8, 0xB5, 0xA2, 0xAF, 0x8C, 0x81, 0x96, 0x9B,
    0xBB, 0xB6, 0xA1, 0xAC, 0x8F, 0x82, 0x95, 0x98, 0xD3, 0xDE, 0xC9, 0xC4, 0xE7, 0xEA, 0xFD, 0xF0,
    0x6B, 0x66, 0x71, 0x7C, 0x5F, 0x52, 0x45, 0x48, 0x03, 0x0E, 0x19, 0x14, 0x37, 0x3A, 0x2D, 0x20,
    0x6D, 0x60, 0x77, 0x7A, 0x59, 0x54, 0x43, 0x4E, 0x05, 0x08, 0x1F, 0x12, 0x31, 0x3C, 0x2B, 0x26,
    0xBD, 0xB0, 0xA7, 0xAA, 0x89, 0x84, 0x93, 0x9E, 0xD5, 0xD8, 0xCF, 0xC2, 0xE1, 0xEC, 0xFB, 0xF6,
    0xD6, 0xDB, 0xCC, 0xC1, 0xE2, 0xEF, 0xF8, 0xF5, 0xBE, 0xB3, 0xA4, 0xA9, 0x8A, 0x87, 0x90, 0x9D,
    0x06, 0x0B, 0x1C, 0x11, 0x32, 0x3F, 0x28, 0x25, 0x6E, 0x63, 0x74, 0x79, 0x5A, 0x57, 0x40, 0x4D,
    0xDA, 0xD7, 0xC0, 0xCD, 0xEE, 0xE3, 0xF4, 0xF9, 0xB2, 0xBF, 0xA8, 0xA5, 0x86, 0x8B, 0x9C, 0x91,
    0x0A, 0x07, 0x10, 0x1D, 0x3E, 0x33, 0x24, 0x29, 0x62, 0x6F, 0x78, 0x75, 0x56, 0x5B, 0x4C, 0x41,
    0x61, 0x6C, 0x7B, 0x76, 0x55, 0x58, 0x4F, 0x42, 0x09, 0x04, 0x13, 0x1E, 0x3D, 0x30, 0x27, 0x2A,
    0xB1, 0xBC, 0xAB, 0xA6, 0x85, 0x88, 0x9F, 0x92, 0xD9, 0xD4, 0xC3, 0xCE, 0xED, 0xE0, 0xF7, 0xFA,
    0xB7, 0xBA, 0xAD, 0xA0, 0x83, 0x8E, 0x99, 0x94, 0xDF, 0xD2, 0xC5, 0xC8, 0xEB, 0xE6, 0xF1, 0xFC,
    0x67, 0x6A, 0x7D, 0x70, 0x53, 0x5E, 0x49, 0x44, 0x0F, 0x02, 0x15, 0x18, 0x3B, 0x36, 0x21, 0x2C,
    0x0C, 0x01, 0x16, 0x1B, 0x38, 0x35, 0x22, 0x2F, 0x64, 0x69, 0x7E, 0x73, 0x50, 0x5D, 0x4A, 0x47,
    0xDC, 0xD1, 0xC6, 0xCB, 0xE8, 0xE5, 0xF2, 0xFF, 0xB4, 0xB9, 0xAE, 0xA3, 0x80, 0x8D, 0x9A, 0x97
};

const unsigned char mul14[256] = {
    0x00, 0x0E, 0x1C, 0x12, 0x38, 0x36, 0x24, 0x2A, 0x70, 0x7E, 0x6C, 0x62, 0x48, 0x46, 0x54, 0x5A,
    0xE0, 0xEE, 0xFC, 0xF2, 0xD8, 0xD6, 0xC4, 0xCA, 0x90, 0x9E, 0x8C, 0x82, 0xA8, 0xA6, 0xB4, 0xBA,
    0xDB, 0xD5, 0xC7, 0xC9, 0xE3, 0xED, 0xFF, 0xF1, 0xAB, 0xA5, 0xB7, 0xB9, 0x93, 0x9D, 0x8F, 0x81,
    0x3B, 0x35, 0x27, 0x29, 0x03, 0x0D, 0x1F, 0x11, 0x4B, 0x45, 0x57, 0x59, 0x73, 0x7D, 0x6F, 0x61,
    0xAD, 0xA3, 0xB1, 0xBF, 0x95, 0x9B, 0x89, 0x87, 0xDD, 0xD3, 0xC1, 0xCF, 0xE5, 0xEB, 0xF9, 0xF7,
    0x4D, 0x43, 0x51, 0x5F, 0x75, 0x7B, 0x69, 0x67, 0x3D, 0x33, 0x21, 0x2F, 0x05, 0x0B, 0x19, 0x17,
    0x76, 0x78, 0x6A, 0x64, 0x4E, 0x40, 0x52, 0x5C, 0x06, 0x08, 0x1A, 0x14, 0x3E, 0x30, 0x22, 0x2C,
    0x96, 0x98, 0x8A, 0x84, 0xAE, 0xA0, 0xB2, 0xBC, 0xE6, 0xE8, 0xFA, 0xF4, 0xDE, 0xD0, 0xC2, 0xCC,
    0x41, 0x4F, 0x5D, 0x53, 0x79, 0x77, 0x65, 0x6B, 0x31, 0x3F, 0x2D, 0x23, 0x09, 0x07, 0x15, 0x1B,
    0xA1, 0xAF, 0xBD, 0xB3, 0x99, 0x97, 0x85, 0x8B, 0xD1, 0xDF, 0xCD, 0xC3, 0xE9, 0xE7, 0xF5, 0xFB,
    0x9A, 0x94, 0x86, 0x88, 0xA2, 0xAC, 0xBE, 0xB0, 0xEA, 0xE4, 0xF6, 0xF8, 0xD2, 0xDC, 0xCE, 0xC0,
    0x7A, 0x74, 0x66, 0x68, 0x42, 0x4C, 0x5E, 0x50, 0x0A, 0x04, 0x16, 0x18, 0x32, 0x3C, 0x2E, 0x20,
    0xEC, 0xE2, 0xF0, 0xFE, 0xD4, 0xDA, 0xC8, 0xC6, 0x9C, 0x92, 0x80, 0x8E, 0xA4, 0xAA, 0xB8, 0xB6,
    0x0C, 0x02, 0x10, 0x1E, 0x34, 0x3A, 0x28, 0x26, 0x7C, 0x72, 0x60, 0x6E, 0x44, 0x4A, 0x58, 0x56,
    0x37, 0x39, 0x2B, 0x25, 0x0F, 0x01, 0x13, 0x1D, 0x47, 0x49, 0x5B, 0x55, 0x7F, 0x71, 0x63, 0x6D,
    0xD7, 0xD9, 0xCB, 0xC5, 0xEF, 0xE1, 0xF3, 0xFD, 0xA7, 0xA9, 0xBB, 0xB5, 0x9F, 0x91, 0x83, 0x8D
};



bool is_valid_hex(const string &input) {
    if (input.size() != 2) return false;
    for (char c : input) {
        if (!isxdigit(c)) return false;
    }
    return true;
}

void generate_random_key(unsigned char roundKey[Nb * 4]) {
    srand(time(nullptr));  
    for (int i = 0; i < Nb * 4; ++i) {
        roundKey[i] = rand() % 256; 
    }
}

void sub_bytes(State &state) {
    cout << "\n| -------------------------------------------- SBOX -------------------------------------------------------------------- |\n";
    cout << "       0      1      2      3      4      5      6      7      8      9      A      B      C      D      E      F\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " 0 |  63  |  7C  |  77  |  7B  |  F2  |  6B  |  6F  |  C5  |  30  |  01  |  67  |  2B  |  FE  |  D7  |  AB  |  76  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " 1 |  CA  |  82  |  C9  |  7D  |  FA  |  59  |  47  |  F0  |  AD  |  D4  |  A2  |  AF  |  9C  |  A4  |  72  |  C0  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " 2 |  B7  |  FD  |  93  |  26  |  36  |  3F  |  F7  |  CC  |  34  |  A5  |  E5  |  F1  |  71  |  D8  |  31  |  15  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " 3 |  04  |  C7  |  23  |  C3  |  18  |  96  |  05  |  9A  |  07  |  12  |  80  |  E2  |  EB  |  27  |  B2  |  75  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " 4 |  09  |  83  |  2C  |  1A  |  1B  |  6E  |  5B  |  A0  |  52  |  3B  |  D6  |  B3  |  29  |  E3  |  2F  |  84  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " 5 |  53  |  D1  |  00  |  ED  |  20  |  FC  |  B1  |  5E  |  A3  |  93  |  2C  |  1A  |  1B  |  6E  |  5B  |  A0  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " 6 |  52  |  3B  |  D6  |  B3  |  29  |  E3  |  2F  |  84  |  53  |  D1  |  00  |  ED  |  20  |  FC  |  B1  |  5E  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " 7 |  A3  |  93  |  2C  |  1A  |  1B  |  6E  |  5B  |  A0  |  52  |  3B  |  D6  |  B3  |  29  |  E3  |  2F  |  84  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " 8 |  53  |  D1  |  00  |  ED  |  20  |  FC  |  B1  |  5E  |  A3  |  93  |  2C  |  1A  |  1B  |  6E  |  5B  |  A0  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " 9 |  52  |  3B  |  D6  |  B3  |  29  |  E3  |  2F  |  84  |  53  |  D1  |  00  |  ED  |  20  |  FC  |  B1  |  5E  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " A |  A3  |  93  |  2C  |  1A  |  1B  |  6E  |  5B  |  A0  |  52  |  3B  |  D6  |  B3  |  29  |  E3  |  2F  |  84  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " B |  53  |  D1  |  00  |  ED  |  20  |  FC  |  B1  |  5E  |  A3  |  93  |  2C  |  1A  |  1B  |  6E  |  5B  |  A0  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " C |  52  |  3B  |  D6  |  B3  |  29  |  E3  |  2F  |  84  |  53  |  D1  |  00  |  ED  |  20  |  FC  |  B1  |  5E  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " D |  A3  |  93  |  2C  |  1A  |  1B  |  6E  |  5B  |  A0  |  52  |  3B  |  D6  |  B3  |  29  |  E3  |  2F  |  84  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " E |  53  |  D1  |  00  |  ED  |  20  |  FC  |  B1  |  5E  |  A3  |  93  |  2C  |  1A  |  1B  |  6E  |  5B  |  A0  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " F |  52  |  3B  |  D6  |  B3  |  29  |  E3  |  2F  |  84  |  53  |  D1  |  00  |  ED  |  20  |  FC  |  B1  |  5E  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << "\n| -------------------------------------------- SBOX -------------------------------------------------------------------- |\n";

    for (int i = 0; i < Nb; ++i) {
        for (int j = 0; j < Nb; ++j) {
            state[i][j] = s_box[state[i][j]];
        }
    }
}

#include <iostream>

using namespace std;

void inv_sub_bytes(State &state) {
    
    cout << "       0      1      2      3      4      5      6      7      8      9      A      B      C      D      E      F\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " 0 |  63  |  7C  |  77  |  7B  |  F2  |  6B  |  6F  |  C5  |  30  |  01  |  67  |  2B  |  FE  |  D7  |  AB  |  76  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " 1 |  CA  |  82  |  C9  |  7D  |  FA  |  59  |  47  |  F0  |  AD  |  D4  |  A2  |  AF  |  9C  |  A4  |  72  |  C0  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " 2 |  B7  |  FD  |  93  |  26  |  36  |  3F  |  F7  |  CC  |  34  |  A5  |  E5  |  F1  |  71  |  D8  |  31  |  15  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " 3 |  04  |  C7  |  23  |  C3  |  18  |  96  |  05  |  9A  |  07  |  12  |  80  |  E2  |  EB  |  27  |  B2  |  75  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " 4 |  09  |  83  |  2C  |  1A  |  1B  |  6E  |  5B  |  A0  |  52  |  3B  |  D6  |  B3  |  29  |  E3  |  2F  |  84  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " 5 |  53  |  D1  |  00  |  ED  |  20  |  FC  |  B1  |  5E  |  A3  |  93  |  2C  |  1A  |  1B  |  6E  |  5B  |  A0  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " 6 |  52  |  3B  |  D6  |  B3  |  29  |  E3  |  2F  |  84  |  53  |  D1  |  00  |  ED  |  20  |  FC  |  B1  |  5E  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " 7 |  A3  |  93  |  2C  |  1A  |  1B  |  6E  |  5B  |  A0  |  52  |  3B  |  D6  |  B3  |  29  |  E3  |  2F  |  84  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " 8 |  53  |  D1  |  00  |  ED  |  20  |  FC  |  B1  |  5E  |  A3  |  93  |  2C  |  1A  |  1B  |  6E  |  5B  |  A0  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " 9 |  52  |  3B  |  D6  |  B3  |  29  |  E3  |  2F  |  84  |  53  |  D1  |  00  |  ED  |  20  |  FC  |  B1  |  5E  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " A |  A3  |  93  |  2C  |  1A  |  1B  |  6E  |  5B  |  A0  |  52  |  3B  |  D6  |  B3  |  29  |  E3  |  2F  |  84  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " B |  53  |  D1  |  00  |  ED  |  20  |  FC  |  B1  |  5E  |  A3  |  93  |  2C  |  1A  |  1B  |  6E  |  5B  |  A0  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " C |  52  |  3B  |  D6  |  B3  |  29  |  E3  |  2F  |  84  |  53  |  D1  |  00  |  ED  |  20  |  FC  |  B1  |  5E  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " D |  A3  |  93  |  2C  |  1A  |  1B  |  6E  |  5B  |  A0  |  52  |  3B  |  D6  |  B3  |  29  |  E3  |  2F  |  84  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " E |  53  |  D1  |  00  |  ED  |  20  |  FC  |  B1  |  5E  |  A3  |  93  |  2C  |  1A  |  1B  |  6E  |  5B  |  A0  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";
    cout << " F |  52  |  3B  |  D6  |  B3  |  29  |  E3  |  2F  |  84  |  53  |  D1  |  00  |  ED  |  20  |  FC  |  B1  |  5E  |\n";
    cout << "     +----------------------------------------------------------------------------------------------------------------+\n";

    for (int i = 0; i < Nb; ++i) {
        for (int j = 0; j < Nb; ++j) {
            state[i][j] = inv_s_box[state[i][j]];
        }
    }
}

void shift_rows(State &state) {
    State temp = state;
    for (int i = 1; i < Nb; ++i) {
        for (int j = 0; j < Nb; ++j) {
            state[i][j] = temp[i][(j + i) % Nb];
        }
    }
}

void inv_shift_rows(State &state) {
    State temp = state;
    for (int i = 1; i < Nb; ++i) {
        for (int j = 0; j < Nb; ++j) {
            state[i][(j + i) % Nb] = temp[i][j];
        }
    }
}


void mixColumns(State &state) {

    cout << "\n| --- MixColumns Matrix --- | - Encrypt\n";
    cout << "|\t02 03 01 01\t|\n";
    cout << "|\t01 02 03 01\t|\n";
    cout << "|\t01 01 02 03\t|\n";
    cout << "|\t03 01 01 02\t|\n";
    cout << "|--------------------------|\n";
    cout << "\n| ------ Mix Columns Solution ------ |";
    for (int i = 0; i < Nb; ++i) {
        cout << "\n\n--- Column " << (i + 1) << " ---\n";

        cout << "Column " << (i + 1) << " (slot 1):\n";
        cout << "    02 x " << setw(2) << hex << uppercase << (int)state[0][i] << " = " 
             << setw(2) << (int)(mul2[state[0][i]]) << "\n";
        cout << "    03 x " << setw(2) << (int)state[1][i] << " = " 
             << setw(2) << (int)(mul3[state[1][i]]) << "\n";
        cout << "    01 x " << setw(2) << (int)state[2][i] << " = " 
             << setw(2) << (int)state[2][i] << "\n";
        cout << "    01 x " << setw(2) << (int)state[3][i] << " = " 
             << setw(2) << (int)state[3][i] << "\n";
        cout << "    xor = " << setw(2) << (int)(mul2[state[0][i]] ^ mul3[state[1][i]] ^ state[2][i] ^ state[3][i]) << "\n\n";

        cout << "Column " << (i + 1) << " (slot 2):\n";
        cout << "    01 x " << setw(2) << (int)state[0][i] << " = " 
             << setw(2) << (int)state[0][i] << "\n";
        cout << "    02 x " << setw(2) << (int)state[1][i] << " = " 
             << setw(2) << (int)(mul2[state[1][i]]) << "\n";
        cout << "    03 x " << setw(2) << (int)state[2][i] << " = " 
             << setw(2) << (int)(mul3[state[2][i]]) << "\n";
        cout << "    01 x " << setw(2) << (int)state[3][i] << " = " 
             << setw(2) << (int)state[3][i] << "\n";
        cout << "    xor = " << setw(2) << (int)(state[0][i] ^ mul2[state[1][i]] ^ mul3[state[2][i]] ^ state[3][i]) << "\n\n";

        cout << "Column " << (i + 1) << " (slot 3):\n";
        cout << "    01 x " << setw(2) << (int)state[0][i] << " = " 
             << setw(2) << (int)state[0][i] << "\n";
        cout << "    01 x " << setw(2) << (int)state[1][i] << " = " 
             << setw(2) << (int)state[1][i] << "\n";
        cout << "    02 x " << setw(2) << (int)state[2][i] << " = " 
             << setw(2) << (int)(mul2[state[2][i]]) << "\n";
        cout << "    03 x " << setw(2) << (int)state[3][i] << " = " 
             << setw(2) << (int)(mul3[state[3][i]]) << "\n";
        cout << "    xor = " << setw(2) << (int)(state[0][i] ^ state[1][i] ^ mul2[state[2][i]] ^ mul3[state[3][i]]) << "\n\n";

        cout << "Column " << (i + 1) << " (slot 4):\n";
        cout << "    03 x " << setw(2) << (int)state[0][i] << " = " 
             << setw(2) << (int)(mul3[state[0][i]]) << "\n";
        cout << "    01 x " << setw(2) << (int)state[1][i] << " = " 
             << setw(2) << (int)state[1][i] << "\n";
        cout << "    01 x " << setw(2) << (int)state[2][i] << " = " 
             << setw(2) << (int)state[2][i] << "\n";
        cout << "    02 x " << setw(2) << (int)state[3][i] << " = " 
             << setw(2) << (int)(mul2[state[3][i]]) << "\n";
        cout << "    xor = " << setw(2) << (int)(mul3[state[0][i]] ^ state[1][i] ^ state[2][i] ^ mul2[state[3][i]]) << "\n\n";
    }
    cout << "\n| ------ End of Mix Columns Solution ------ |\n";
    for (int i = 0; i < Nb; ++i) {
        unsigned char a0 = state[0][i];
        unsigned char a1 = state[1][i];
        unsigned char a2 = state[2][i];
        unsigned char a3 = state[3][i];

        state[0][i] = mul2[a0] ^ mul3[a1] ^ a2 ^ a3;
        state[1][i] = a0 ^ mul2[a1] ^ mul3[a2] ^ a3;
        state[2][i] = a0 ^ a1 ^ mul2[a2] ^ mul3[a3];
        state[3][i] = mul3[a0] ^ a1 ^ a2 ^ mul2[a3];
    }
}


void inv_mix_columns(State &state) {
    cout << "\n| --- MixColumns Matrix --- |\n - Decrypt";
    cout << "|\t0E 0B 0D 09\t|\n"; 
    cout << "|\t09 0E 0B 0D\t|\n";
    cout << "|\t0D 09 0E 0B\t|\n";
    cout << "|\t0B 0D 09 0E\t|\n";
    cout << "|--------------------------|\n";


    for (int i = 0; i < Nb; ++i) {
        unsigned char a0 = state[0][i];
        unsigned char a1 = state[1][i];
        unsigned char a2 = state[2][i];
        unsigned char a3 = state[3][i];

        state[0][i] = mul14[a0] ^ mul11[a1] ^ mul13[a2] ^ mul9[a3];
        state[1][i] = mul9[a0] ^ mul14[a1] ^ mul11[a2] ^ mul13[a3];
        state[2][i] = mul13[a0] ^ mul9[a1] ^ mul14[a2] ^ mul11[a3];
        state[3][i] = mul11[a0] ^ mul13[a1] ^ mul9[a2] ^ mul14[a3];
    }
}

void add_round_key(State &state, const unsigned char roundKey[Nb * 4]) {
    cout << "\n| --- Add Round Solution --- |\n";
    for (int i = 0; i < Nb; ++i) {
        for (int j = 0; j < Nb; ++j) {
            unsigned char stateValue = state[i][j];
            unsigned char keyValue = roundKey[i * Nb + j];

            bitset<8> stateBinary(stateValue);
            bitset<8> keyBinary(keyValue);
            
            unsigned char xorResult = stateValue ^ keyValue;
            bitset<8> xorBinary(xorResult);
            
            cout << "state[" << i << "][" << j << "] = " << hex << int(stateValue) 
                 << " (" << stateBinary << ")" << endl;
            cout << "roundKey[" << i << "][" << j << "] = " << hex << int(keyValue) 
                 << " (" << keyBinary << ")" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Result: " << hex << int(xorResult) << " (" << xorBinary << ")" << endl << endl;

            state[i][j] = xorResult;
        }
    }
     cout << "\n| --- End of Add Round Solution --- |\n\n";
}


void display_state(const State &state) {
    const int boxWidth = 4;
    for (int i = 0; i < Nb; ++i) {
        cout << "+";
        for (int j = 0; j < Nb; ++j) {
            cout << string(boxWidth, '-') ;
        }
        cout << "---+";
        cout << endl;
        cout << "| ";
        for (int j = 0; j < Nb; ++j) {
            cout << hex << setw(2) << setfill('0') << (int)state[i][j] << " | ";
        }
        cout << endl;
    }

    cout << "+";
    for (int j = 0; j < Nb; ++j) {
        cout << string(boxWidth, '-') << "+";
    }
    cout << endl;
}

class AES {
public:
    int input() {
        system("cls");
        cout << "\n\n| ===== AES ===== |\n\n";
        State state(Nb, vector<unsigned char>(Nb));
        unsigned char round_key[Nb * 4];
        bool encrypt = true;

        char enc_choice;
        cout << "1.) Encrypt \n";
        cout << "2.) Decrypt \n";
        cout << "3.) Go Back to Main Menu \n";
        cout << "\nEnter your choice: ";
        cin >> enc_choice;
        if (enc_choice == '1') {
            cout << "\n\n| ----- YOU HAVE CHOSEN ENCRYPT ----- |\n\n";            
            encrypt = true;
        }
        else if(enc_choice == '2'){
            cout << "\n\n| ----- YOU HAVE CHOSEN DECRYPT ----- |";
            encrypt = false;
        }
        else if(enc_choice == '3'){
            return go_back();
        }
        else{
            return again();
        }

        cout << "\n| -------- USER INPUT FOR PLAIN TEXT (TWO DIGITS/LETTERS ONLY) -------- |\n";
        cout << "\nEnter your HexaDecimal Values: ";
        for (int i = 0; i < Nb; ++i) {
            for (int j = 0; j < Nb; ++j) {
                string input;
                bool valid_input = false;
                while (!valid_input) {
                    cout << "\n\nUserMatrix [" << i << "][" << j << "]: ";
                    cin >> input;
                    if (is_valid_hex(input)) {
                        state[i][j] = (unsigned char)strtoul(input.c_str(), nullptr, 16);
                        valid_input = true;
                    } else {
                        cout << "\n\nInvalid input! Please enter a valid 2-digit hexadecimal value (00 to FF)." << endl;
                    }
                }
            }
        }
        cout << "\n| -------- USER INPUT FOR PLAIN TEXT (TWO DIGITS/LETTERS ONLY) -------- |\n";


        char key_choice;
        cout << "\n\nInsert Round Key?\n\n";
        cout << "Y.) Yes\n";
        cout << "N.) No\n\n";
        cout << "Enter your choice: ";
        cin >> key_choice;
        if (key_choice == 'y' || key_choice == 'Y') {
            cout << "\n| -------- USER INPUT FOR GIVEN KEY (TWO DIGITS/LETTERS ONLY) -------- |\n";
            cout << "Enter 16 hexadecimal values (2-digit, 00 to FF) for the round key:" << endl;
            for (int i = 0; i < Nb * 4; ++i) {
                string input;
                bool valid_input = false;
                while (!valid_input) {
                    cout << "Key [" << i / Nb << "][" << i % Nb << "]: ";
                    cin >> input;
                    if (is_valid_hex(input)) {
                        round_key[i] = (unsigned char)strtoul(input.c_str(), nullptr, 16);
                        valid_input = true;
                    } else {
                        cout << "Invalid input! Please enter a valid 2-digit hexadecimal value (00 to FF)." << endl;
                    }
                }
            }
            cout << "\n| -------- USER INPUT FOR GIVEN KEY (TWO DIGITS/LETTERS ONLY) -------- |\n\n";
        } else {
            generate_random_key(round_key);
            cout << "Generated random round key: " << endl << endl;
            for (int i = 0; i < Nb * 4; ++i) {
                cout << hex << setw(2) << setfill('0') << (int)round_key[i] << " ";
                if ((i + 1) % Nb == 0) cout << endl;
            }
        }

        cout << "\n--- Starting AES " << (encrypt ? "Encryption" : "Decryption") << " ---\n" << endl;


        for (int round = 1; round <= 10; ++round) {
            cout << "\n\n|| ==== ROUND - [" << round << "] ==== ||\n\n";  

            cout << "\n\n| ------- ADD ROUND FOR " + to_string(round) + " ------- |\n";
            add_round_key(state, round_key);
            display_state(state);
            cout << "\n| ------- ADD ROUND FOR " + to_string(round) + " ------- |\n";

            if (encrypt) {
                cout << "\n| ------- SUB BYTES ROUND " + to_string(round) + " ------- |\n";
                sub_bytes(state);
                display_state(state);
                cout << "\n| ------- SUB BYTES ROUND " + to_string(round) + " ------- |\n";
                cout << "\n| ------- SHIFT ROWS ROUND " + to_string(round) + " ------- |\n";
                shift_rows(state);
                display_state(state);
                cout << "\n| ------- SHIFT ROWS ROUND " + to_string(round) + " ------- |\n";

                if (round <= 10) {
                    cout << "\n| ------- MIX COLUMNS ROUND " + to_string(round) + " ------- |\n";
                    mixColumns(state);
                    display_state(state);
                    cout << "\n| ------- MIX COLUMNS " + to_string(round) + " ------- |\n";
                }
            } else {
                inv_shift_rows(state);
                cout << "\n| ------- INVERSE SHIFT ROWS ROUND " + to_string(round) + " ------- |\n";
                display_state(state);
                cout << "\n| ------- INVERSE SHIFT ROWS ROUND " + to_string(round) + " ------- |\n";
                cout << "\n| ------- INVERSE SUB BYTES ROUND " + to_string(round) + " ------- |\n";
                inv_sub_bytes(state);
                display_state(state);
                cout << "\n| ------- INVERSE SUB BYTES ROUND " + to_string(round) + " ------- |\n";
                cout << "\n";

                if (round < 10) {
                    inv_mix_columns(state);
                    display_state(state);
                    cout << "\n";
                }
            }

            cout << "\n\n|| ==== ROUND - [" << round << "] ==== ||\n\n";  
        }

        return again();
    }
};
