
#include "NeuralWork.h"
int main()
{
    NeuralWork tm({ 2,2,2 });
    vector<double> results = tm.FeedForward({ 1,0 });
    tm;
}

