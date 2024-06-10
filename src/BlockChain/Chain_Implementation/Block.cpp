#include "Block.h"
#include "../Crypt_Imp/sha256.h"
#include <chrono>
#include <sstream>


Block::Block(uint32_t nIndexIn, string sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) {
    _nNonce = -1;
    _tTime = time(nullptr);
}

string Block::GetHash() {
    return _sHash;
}


void Block::MineBlock(uint32_t nDifficulty) {
    string str(nDifficulty, '0');

    auto start_time = std::chrono::high_resolution_clock::now();

    do {
        ++_nNonce;
        _sHash = _CalculateHash();
    }
    while(str != _sHash.substr(0, nDifficulty));

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durr = (end_time - start_time);

    cout<<"Block of Index: "<<_nIndex<<" mined in "<<durr.count()<<" in seconds."<<endl;
}


inline string Block::_CalculateHash() const {
    stringstream ss("");

    ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;

    return sha256(ss.str());
}
