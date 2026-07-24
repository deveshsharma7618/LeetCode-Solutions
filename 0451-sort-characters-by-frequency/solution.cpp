class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> temp;
        for(char ch : s){
            if(temp.find(ch) == temp.end()){
                temp[ch] = 1;
            }else{
                temp[ch]++;
            }
        }

        priority_queue<pair<int,char>> max_heap;
        for(auto const [ch, freq]: temp){
            max_heap.push({freq, ch});
        }

        string ans = "";

        while(!max_heap.empty()){
            char ch = max_heap.top().second;
            int freq = max_heap.top().first;
            cout << ch << " << " << freq << endl;
            for(int i = 0; i < freq; i++){
                ans.push_back(ch);
            }
            max_heap.pop();
        }

        return ans;
        
    }
};
