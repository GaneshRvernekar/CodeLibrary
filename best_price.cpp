vector<int> bestPrice(int n,vector<vector<int>> price,int k,int q, vector<vector<int>> queries) {
        // code here
        int m = price[n-1][1];
        
        vector<int> buffer(m+1,0);
        
        for(int i=0;i<price.size();i++)
        {
            for(int j=price[i][0];j<=price[i][1];j++)
            {
                buffer[j]+=1;
            }
        }
        
        vector<int> final_;
        
        for(int i=0;i<buffer.size();i++)
        {
            if(buffer[i]>=k)
            {
                final_.push_back(i);
            }
        }
        
        vector<int> answer(q,0);
        
        for(int i=0;i<queries.size();i++)
        {
            for(int j=0;j<final_.size();j++)
            {
                if(queries[i][0]<=final_[j] && queries[i][1] >= final_[j])
                {
                    answer[i]++;
                }
            }
        }
        
        for(int i=0;i<answer.size();i++)
        {
            cout<<answer[i]<<endl;
        }
    }

   