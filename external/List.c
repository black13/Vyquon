#include "Vyquon.h"

VyObj MakeCons(VyObj*, int);
VyObj MakeList(VyObj*, int);
VyObj GetCar(VyObj*, int);
VyObj GetCdr(VyObj*, int);
VyObj GetListLen(VyObj*, int);

/* Initialize the IO functions and library */
void LoadList(){
    NewFunction("pair", "(x y)", &MakeCons);
    NewFunction("list", "(... all)", &MakeList);

    NewFunction("first",  "(lst)", &GetCar);
    NewFunction("rest",  "(lst)", &GetCdr);

    NewFunction("length", "(lst)", &GetListLen);
}

VyObj MakeCons(VyObj* values, int num_args){
    return Cons(values[0], values[1]);
}
VyObj MakeList(VyObj* values, int num_args){
    VyObj lst = Nil();
    int i;
    for(i = num_args - 1; i >= 0; i--)
        lst = Cons(values[i], lst);
    return lst;
}
VyObj GetCar(VyObj* values, int num_args){
    return Car(values[0]);
}
VyObj GetCdr(VyObj* values, int num_args){
    return Cdr(values[0]);
}

VyObj GetListLen(VyObj* values, int num_args){
    return CreateInt(ListLen(values[0]));
}
