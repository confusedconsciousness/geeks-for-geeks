#include<iostream>
using namespace std;
/*
    We are given some jobs along with their deadlines as well as their associated profits if down within the time specified
        jobs | deadline | profit
    1.   a   |    4     |  70
    2.   b   |    1     |  80
    3.   c   |    1     |  30
    4.   d   |    1     | 100
    a deadline 4 means it can be done in any of the interval 0 - 1, 1 - 2, 2 - 3, 3 - 4
    each job takes 1 slot to complete
    How will you proceed with the problem?
    The idea is to use greedy approach, in that case we'll sort the jobs based on their profit in descending order, thus having the
    highest profit on the top, no we assign that job to the latest time slot available at that moment
    for e.g. d has the highest profit so we select it and as its deadline is 1 so we assign it to 0 - 1
    now the next job is b but as 0 - 1 is occupied we can't choose it thus we skip this job 
    now the next job is a it has deadline of 4 so we'll place it at 3 - 4, so that we can have space for other jobs if they happen to exist
    O/P: 170
 */
int INPUTS[100][2]; // at max there can be 100 jobs

int main(){
    int n; // total jobs (1<n<100)
    cin>>n;
    // dealine, profit
    int f = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 2; ++j){
            cin>>INPUTS[i][j];
        }
    }
    // find the max deadline
    for(int i = 0; i < n; ++i){
        if(INPUTS[i][0] > f){
            f = INPUTS[i][0];
        }
    }
    // now we'll create a time sequence which will be represented by an array
    int timeslot[f];
    // initialise them with 0, which means the time slot is available
    for(int i = 0; i < f; ++i){
        timeslot[i] = 0;
    }
    // index represent the time stamps
    // for e.g. 0 represent 0 -> 1
    //          1 represent 1 -> 2

    // now we need to sort the jobs in descending order
    for(int i = 0; i < n - 1; ++i){
        for(int j = i + 1; j < n; ++j){
            if(INPUTS[j][1] > INPUTS[i][1]){
                swap(INPUTS[j][1], INPUTS[i][1]);
                swap(INPUTS[i][0], INPUTS[j][0]);
            }
        }
    }
    
    int profit = 0;
    // let's pick them up then
    for(int i = 0; i < n; ++i){
        if(timeslot[INPUTS[i][0] - 1] == 0){
            profit += INPUTS[i][1];
            timeslot[INPUTS[i][0] - 1] = 1;
        }else{
            // we can't do it anything but to skip that job
            // find the latest available time slot
            for(int j = INPUTS[i][0] - 1; j > -1; --j){
                if(timeslot[j] == 0){
                    profit += INPUTS[i][1];
                    timeslot[j] = 1;
                    break;
                }
            }

        }
    }
    cout<<"MAX profit: "<<profit;
}