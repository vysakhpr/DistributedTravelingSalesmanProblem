rpcgen tsp.x
rpcgen tspserver.x
gcc manager.c tsp_clnt.c -o manager -lnsl
gcc tsp_proc.c tsp_svc.c tspserver_clnt.c -o tsp_proc -lnsl
gcc server.c tspserver_svc.c -o tspserver -lnsl


./manager 0
./tsp_proc
./tspserver