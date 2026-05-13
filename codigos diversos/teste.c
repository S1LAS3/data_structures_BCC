void Selection_Sort(int num[],int n){
	for(int j = 0; j<n-1; j++){
	
		int min_index = j;
		
		for(int i = j+1; i < n; i++){
			
			if (num[i] < num[min_index]){
				
				min_index = i;
			}
		}
		
		if(num[j] > num[min_index]){
			
			int aux = num[j];
			num[j] = num[min_index];
			num[min_index] = aux;
			
		}	
	}
}