#include <iostream>
#include <vector>

using namespace std;
#if 0
/*
 * Mark & Toy
 * https://www.hackerrank.com/challenges/mark-and-toys/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting
 * Greedy Approach
 */
int maximumToys(vector<int> prices, int k) {
    sort(prices.begin(), prices.end());
    int price = 0;
    int count = 0;
    for(int i = 0; i< prices.size(); i++){
        price = price + prices[i];
        if(price > k) {
            break;
        }
        count++;
    }
    return count;
}

/*
 * Sorting: Comparator
 * https://www.hackerrank.com/challenges/ctci-comparator-sorting/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting
 */
 struct Player {
    int score;
    string name;
};

class Checker{
public:
  	// complete this method
    static int comparator(Player a, Player b)  {
        if(a.score < b.score) {
            return -1;
        } else if(a.score > b.score) {
            return 1;
        } else {
            int l1 = a.name.length();
            int l2 = b.name.length();
            int i = 0;
            while(1) {
                if ((a.name[i] == '\n') && (b.name[i] == '\n')) {
                  return 0;  
                } else if(a.name[i] == '\n'){
                    return -1;
                } else if (b.name[i] == '\n'){
                    return 1;
                }
                if(a.name[i] > b.name[i]) {
                    return -1;
                } else if (a.name[i] < b.name[i]) {
                    return 1;
                }
                i++;
            }
            return 0;
        }
    }
}; 

/*
 * Fraudulent Activity Notifications
 * https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting
 * TODO this solution is correct but it exceeds the timing need to optimize the function findMaidan 
 */
float static findMaidan(vector<int> exp, int idx, int d){
    vector<int> arr;
    float med = 0;
    bool isEven = ((d%2)==0) ? true : false;
    int ref = floor(d/2);

    for(int i = 0; i<d; i++){
        arr.push_back(exp[idx-d]);
        idx++;
    }
    cout << endl;
    std::sort(arr.begin(), arr.end());
    if (isEven) {
        med = (arr[ref] + arr[ref+1])/2;
    } else {
        med = arr[ref];
    }
    return med;
}

int activityNotifications(vector<int> expenditure, int d) {
    int len = expenditure.size();
    int notification = 0;
    for (int i = d; i< len; i++) {
        float med = findMaidan(expenditure, i, d);
        cout << med << " " << med*2 << " " << expenditure[i] << endl;
        if ((med*2) <= expenditure[i]) {
            notification++;
        }     
    }
    return notification;
}

#endif

//expenditure can happen only up to 200 while d can go upto 2*10^5
float static findMaidan(vector<int> exp, int idx, int d, bool firstTime ){
    //get the array of counts then find (d/2+ d/2+1) of (d/2+1)
    /*for(int i = 0; i< exp.size(); i++){
            cout << exp[i] << "  ";
    }*/
    cout << endl;
    static vector<int> count(201, 0);
    float med = 0;
    bool isEven = ((d%2)==0) ? true : false;
    int ref = floor(d/2);
    cout << idx << "    " << d << endl;
    if(firstTime) {
        for(int i = 0; i<d; i++){
            count[exp[idx-d]]++;
            idx++;
        }
    } else {
        count[exp[idx-d-1]]--;
        count[exp[idx]]++;
    }
    int idx1 = 0;
    int sum = 0;
    while(1){
        sum += count[idx1];
        if(sum >= (floor(d/2)+1)){
            break;
        }
        idx1++;
    }
    cout << "---"<<idx1<< floor(d/2)<< sum << endl;

    if (isEven) {
        if (sum == (floor(d/2)+1)) {
            if(count[idx1] > 1) {
                return idx1;
            }
            int i;
            for(i = idx1-1; i>=0; i--){
                if(count[i]!= 0)
                    break;
            }
            med = (idx1 + i)/(float)2; 

        } else {
            med = idx1;
        }
    } else {
        med = idx1;
    }
    return med;
}

int activityNotifications(vector<int> expenditure, int d) {
    /*
    for(int i = 0; i< expenditure.size(); i++){
            cout << expenditure[i] << "  ";
    }
    cout << endl;
    */
    int len = expenditure.size();
    int notification = 0;
    bool isFirstTime = true;
    for (int i = d; i< len; i++) {
        float med = findMaidan(expenditure, i, d, isFirstTime);
        isFirstTime = false;
        cout << med << endl;
        if ((med*2) <= expenditure[i]) {
            notification++;
        }     
    }
    return notification;
}

int main () {
    int array[] = {1, 2, 3, 4, 4};
    int d = 4;
    vector<int> expenditure (array, array + sizeof(array) / sizeof(int) );
    cout << activityNotifications(expenditure, d) << endl;
}