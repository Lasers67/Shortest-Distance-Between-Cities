int no_of_cities;
int min_distance_index(int dist[], int cityVisited[])
{
	int min_dist = INT_MAX, index;
	for(int i=0;i<no_of_cities;i++)
	{
		if(min_dist>=dist[i] && cityVisited[i]==0)
		{
			index = i;
			min_dist = dist[i];
		}
	}
	return index;
}
void dijkstra_run(int table[no_of_cities][no_of_cities],int src_city)
{
	int dist[no_of_cities], cityVisited[no_of_cities], parentCity[no_of_cities],i;

	for(i=0;i<no_of_cities;i++)
	{
		dist[i]= INT_MAX;
		cityVisited[i] = 0;
		parentCity = -1;

	}

	dist[src_city]=0;
	
	for(i=0;i<no_of_cities-1;i++)
	{
		u=min_distance_index(dist,cityVisited);
		cityVisited[u]=1;
		for(i=0;i<no_of_cities;i++)
		{
			if((dist[u]+table[u][i]<dist[i]) && cityVisited[i]==0 && table[u][i]>0)
			{
				dist[i] = dist[u]+table[u][i];
				parentCity[i] = u;
			}
		}
	
	}
	printSolution(dist,parentCity);
	return;
}