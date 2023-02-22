//
// Created by rwkramer on 10/21/22.
//

#include "mrs.h"

MRSCodec::MRSCodec(uint32_t _nRadices,const uint32_t *_radices) {

    // dynamically make space for array
    radices = new uint32_t[_nRadices];

    // remember count
    nRadices = _nRadices;

    // copy radix list into newly created array
    for (uint32_t i=0;i<nRadices;i++)
        radices[i] = _radices[i];
}

MRSCodec::~MRSCodec() {
    delete[] radices;
}

uint32_t MRSCodec::encode(uint32_t *digits) {
    uint32_t result = 0;

    for (int i = 0; i < nRadices - 1; i++) {
        result = result * radices[i] + digits[i];
    }

    return result;
}

void MRSCodec::decode(uint32_t value,uint32_t *digits) {
    for (int i = nRadices - 1; i >= 0; i--) {
        digits[i] = value % radices[i];

        value = value / radices[i];
    }
}
