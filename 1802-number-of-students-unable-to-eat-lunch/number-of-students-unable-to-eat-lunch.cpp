class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& sd)
    {
        int ans=st.size();
        vector<int>hashh(2);
        hashh[0]=count(st.begin(),st.end(),0);
        hashh[1]=ans-hashh[0];

        for(int i:sd)
        {
            if(hashh[i]>0)
            {
                --ans;
                --hashh[i];
            }
            else
                return ans;
        }
        return 0;
    }
};