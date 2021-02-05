/*
 * Candy
 * https://www.hackerrank.com/challenges/candies/problem?filter=India&filter_on=country&h_l=interview&page=1&playlist_slugs%5B%5D=nutanix
 */

long candies(int n, vector<int> arr) {
 vector<int> candy;
 candy.push_back(1);
 for (int i = 1; i< n; i++) {
     if (arr[i-1] < arr[i]){
         candy.push_back(candy[i-1]+1);
     } else {
         candy.push_back(1);
     }
 } 
 for (int i = n-1; i>0; i--){
     if((arr[i-1]>arr[i]) && (candy[i-1] <= candy[i])) {
         candy[i-1] = candy[i]+1;
     }
 }
 vector<int> :: iterator it;
 long count = 0;
 for(it = candy.begin(); it != candy.end(); it++){
     count += *it;
     cout << *it << " ";
 }
 return count;
} 