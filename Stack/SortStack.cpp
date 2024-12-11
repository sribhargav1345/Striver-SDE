#include <bits/stdc++.h> 

void sortInsert(stack<int>& st,int op)
{
	if(st.empty() || st.top() <= op)
	{
		st.push(op);
		return;
	}

	int ok = st.top();
	st.pop();

	sortInsert(st,op);

	st.push(ok);
}

void sortStack(stack<int> &st)
{
	if(st.empty())
	{
		return;
	}

	int op = st.top();
	st.pop();

	sortStack(st);

	sortInsert(st,op);
}