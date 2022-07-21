//
// Created by Administrator on 2022/7/22.
//

#include "Gloable.h"

struct ElemType {
  int value;
};

typedef struct ElemType *Triplet;

// 构造
Status initTriplet(Triplet *t, struct ElemType v1, struct ElemType v2, struct ElemType v3);

//销毁
Status destroyTriplet(Triplet *t);

//获取
Status get(Triplet *t,int i,struct ElemType e);
