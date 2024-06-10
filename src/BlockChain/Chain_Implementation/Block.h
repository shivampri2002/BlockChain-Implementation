#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include <cstdint>
#include <iostream>

using namespace std;


class Block {
public:
    string sPrevHash;

    Block(uint32_t nIndexIn, string sDataIn);

    string GetHash();

    void MineBlock(uint32_t nDifficulty);

private:
    uint32_t _nIndex;
    int64_t _nNonce;
    string _sData;
    string _sHash;
    time_t _tTime;

    string _CalculateHash() const;
};



#endif // BLOCK_H_INCLUDED
