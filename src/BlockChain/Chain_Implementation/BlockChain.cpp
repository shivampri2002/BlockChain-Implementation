#include "Block.h"
#include "BlockChain.h"


Blockchain::Blockchain() {
    _vChain.push_back(Block(0, "Genesis Block"));
    _nDifficulty = 4;
}

void Blockchain::AddBlock(Block bNew){
    bNew.sPrevHash = _GetLastBlock().GetHash();
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const {
    return _vChain.back();
}
