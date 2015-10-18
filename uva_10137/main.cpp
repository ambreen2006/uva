#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    int N;
    while(1)
    {
        cin >> N;
        if (N == 0)
            break;
        double students[N];
        double sum = 0;
        double average = 0;
        double paid_more = 0;
        double paid_less = 0;

        for(int i = 0; i < N; i++)
        {
            cin >> students[i];
            sum += students[i];
        }

        average = sum/N;
        for (int j = 0; j < N; ++j) {
            double extra = (double) (long) ((students[j]-average) * 100.0) / 100.0;
            if(extra > 0) {
                paid_more += extra;
            }
            else
                paid_less += -extra;

        }
        double cover_cost = (paid_less > paid_more) ? paid_less : paid_more;
        printf("$%.2lf\n",cover_cost);
    }
    return 0;
}
