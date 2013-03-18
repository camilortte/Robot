#include "estado.h"

Estado::Estado(double costo, int item)
{
    this->costo=costo;
    this->item=item;
}

void Estado::setCosto(double costo)
{
    this->costo=costo;
}

void Estado::setItem(int item)
{
    this->item=item;
}

double Estado::getCosto()
{
    return costo;
}

int Estado::getItem()
{
    return item;
}
