#include<iostream>
#include<cstdio>
#include<map>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
  int t;
  scanf("%d",&t);
  for(int tt=0;tt<t;tt++)
    {

      int m,n,k;
      scanf("%d %d %d",&m,&n,&k);
      if(n>m) n=m;
      int time[m],interval[m];

      for(int i=0;i<m;i++)
	scanf("%d",&time[i]);
      for(int i=0;i<m;i++)
	scanf("%d",&interval[i]);

      //  Use binary search for the optimal answer.
      //....since we can check the answer validity in const time.
      int lo=0,hi=1e9,mid;
      


      while(hi>lo+1)
	{
	  vector<int> temp;
	  temp.resize(m);

	  mid=(long long)((long long)lo+(long long)(hi-lo)/2);

	  //....now check the validity for the mid value.
	  for(int i=0;i<m;i++)
	    {
	      if(mid>=time[i])
		temp[i]=1+(mid-time[i])/interval[i];
	      else temp[i]=0;
	    }
	  sort(temp.rbegin(),temp.rend());

	  long long sum=0;
	  for(int i=0;i<n;i++)
	    sum+=temp[i];

	  if(sum>=k)
	    hi=mid;
	  else
	    lo=mid;
	}
      printf("%d\n",hi);

    }

  return 0;
}
