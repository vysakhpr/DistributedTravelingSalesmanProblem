/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _TSP_H_RPCGEN
#define _TSP_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


#define TSPPROG 0x20000001
#define TRAVERSEVERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define TRAVERSE 1
extern  int * traverse_1(char **, CLIENT *);
extern  int * traverse_1_svc(char **, struct svc_req *);
extern int tspprog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define TRAVERSE 1
extern  int * traverse_1();
extern  int * traverse_1_svc();
extern int tspprog_1_freeresult ();
#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_TSP_H_RPCGEN */
