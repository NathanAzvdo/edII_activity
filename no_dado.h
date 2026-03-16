#ifndef NO_DADO_H
#define NO_DADO_H

class no_dado {
public:
    int info;
    no_dado* prox;

    no_dado();
    no_dado(int x, no_dado* ptr);
};

#endif