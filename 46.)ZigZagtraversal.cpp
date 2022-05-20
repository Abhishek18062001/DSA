vector<int>ans;
    	bool ltof=true;
    	if(root== NULL)
    	return ans;
    	queue<Node*> q;
    	q.push(root);
    	while(!q.empty()){
    	    int size=q.size();
    	    vector<int> temp(size);
    	    for(int i=0;i<size;i++){
    	        Node* curr=q.front();
    	        q.pop();
    	        int index;
    	        if(ltof){
    	          index=i;
    	        }else{
    	            index=size-i-1;
    	        }
    	        temp[index]=curr->data;
    	        if(curr->left!=NULL){
    	            q.push(curr->left);
    	        }else{
    	            q.push(curr->right);
    	        }
    	       cout<<i<<" " ;
    	    }
    	    ltof=!ltof;
    	   for(int i=0;i<temp.size();i++){
    	       ans.push_back(temp[i]);
    	   }
    	    
    	    
    	}
    	return ans;
