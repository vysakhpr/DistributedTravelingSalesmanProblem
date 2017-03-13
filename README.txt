rpcgen tsp.x
gcc manager.c tsp_clnt.c -o manager -lnsl
gcc tsp_proc.c tsp_svc.c -o tspserver -lnsl

./manager 0
./server