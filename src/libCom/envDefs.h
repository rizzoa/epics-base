/*	$Id$	
 *	Author:	Roger A. Cole
 *	Date:	07-20-91
 *
 *	Experimental Physics and Industrial Control System (EPICS)
 *
 *	Copyright 1991, the Regents of the University of California,
 *	and the University of Chicago Board of Governors.
 *
 *	This software was produced under  U.S. Government contracts:
 *	(W-7405-ENG-36) at the Los Alamos National Laboratory,
 *	and (W-31-109-ENG-38) at Argonne National Laboratory.
 *
 *	Initial development by:
 *		The Controls and Automation Group (AT-8)
 *		Ground Test Accelerator
 *		Accelerator Technology Division
 *		Los Alamos National Laboratory
 *
 *	Co-developed with
 *		The Controls and Computing Group
 *		Accelerator Systems Division
 *		Advanced Photon Source
 *		Argonne National Laboratory
 *
 * Modification Log:
 * -----------------
 * .01	07-20-91	rac	initial version
 * .02  08-07-91	joh	added ioc log env
 * .03  09-26-94	joh	ifdef out double inclusion	
 * .04  11-28-94	joh	new CA env var 
 * .05  04-20-95	anj	moved defaults to CONFIG_ENV
 * .06  09-11-96	joh 	ANSI prototypes	
 * .07  09-18-96	joh 	added envParamIsEmpty()	
 * .08  03-18-97	joh 	remove env param length limit	
 *
 * make options
 *	-DvxWorks	makes a version for VxWorks
 *	-DNDEBUG	don't compile assert() checking
 *      -DDEBUG         compile various debug code, including checks on
 *                      malloc'd memory
 */
/*+/mod***********************************************************************
* TITLE	envDefs.h - definitions for environment get/set routines
*
* DESCRIPTION
*	This file defines the environment parameters for EPICS.  These
*	ENV_PARAM's are initialized by $epics/share/bin/envSetupParams for
*	use by EPICS programs running under UNIX and VxWorks.
*
*	User programs can define their own environment parameters for their
*	own use--the only caveat is that such parameters aren't automatically
*	setup by EPICS.
*
* SEE ALSO
*	$epics/share/bin/envSetupParams, envSubr.c
*
*-***************************************************************************/

#ifndef envDefsH
#define envDefsH

#ifdef __cplusplus
extern "C" {
#endif

#include "shareLib.h"
#include "osiSock.h"

typedef struct envParam {
    char	*name;		/* text name of the parameter */
    char	*pdflt;
} ENV_PARAM;

/*
 * bldEnvData looks for "epicsShareExtern const ENV_PARAM"
 */
epicsShareExtern const ENV_PARAM EPICS_CA_ADDR_LIST; 
epicsShareExtern const ENV_PARAM EPICS_CA_CONN_TMO; 
epicsShareExtern const ENV_PARAM EPICS_CA_BEACON_PERIOD; 
epicsShareExtern const ENV_PARAM EPICS_CA_AUTO_ADDR_LIST;
epicsShareExtern const ENV_PARAM EPICS_CA_REPEATER_PORT;
epicsShareExtern const ENV_PARAM EPICS_CA_SERVER_PORT;
epicsShareExtern const ENV_PARAM EPICS_CAS_INTF_ADDR_LIST;
epicsShareExtern const ENV_PARAM EPICS_CAS_BEACON_ADDR_LIST; 
epicsShareExtern const ENV_PARAM EPICS_CAS_SERVER_PORT;
epicsShareExtern const ENV_PARAM EPICS_TS_MIN_WEST;
epicsShareExtern const ENV_PARAM EPICS_TS_NTP_INET;
epicsShareExtern const ENV_PARAM EPICS_IOC_LOG_PORT;
epicsShareExtern const ENV_PARAM EPICS_IOC_LOG_INET;
epicsShareExtern const ENV_PARAM EPICS_IOC_LOG_FILE_LIMIT;
epicsShareExtern const ENV_PARAM EPICS_IOC_LOG_FILE_NAME;
epicsShareExtern const ENV_PARAM EPICS_IOC_LOG_FILE_COMMAND;
epicsShareExtern const ENV_PARAM EPICS_CMD_PROTO_PORT;
epicsShareExtern const ENV_PARAM EPICS_AR_PORT;
#define EPICS_ENV_VARIABLE_COUNT 18

/*
 * N elements added here to satisfy microsoft development tools
 * (includes room for nill termination)
 *
 * bldEnvData looks for "epicsShareExtern ENV_PARAM" so
 * this always needs to be divided into two lines
 */
epicsShareExtern const ENV_PARAM
	*env_param_list[EPICS_ENV_VARIABLE_COUNT+1];

#if defined(__STDC__) || defined(__cplusplus)
char * epicsShareAPI envGetConfigParam(const ENV_PARAM *pParam, 
				int bufDim, char *pBuf);
const char * epicsShareAPI envGetConfigParamPtr(const ENV_PARAM *pParam);
long epicsShareAPI envPrtConfigParam(const ENV_PARAM *pParam);
long epicsShareAPI envSetConfigParam(const ENV_PARAM *pParam, 
			char *value);
long epicsShareAPI envGetInetAddrConfigParam(const ENV_PARAM *pParam, 
			struct in_addr *pAddr);
long epicsShareAPI envGetDoubleConfigParam(const ENV_PARAM *pParam, 
			double *pDouble);
long epicsShareAPI envGetLongConfigParam(const ENV_PARAM *pParam, 
			long *pLong);
const char * epicsShareAPI envGetConfigParamPtr(const ENV_PARAM *pParam);
#else
char * epicsShareAPI envGetConfigParam();
char * epicsShareAPI envGetConfigParamPtr();
long epicsShareAPI envPrtConfigParam();
long epicsShareAPI envSetConfigParam();
long epicsShareAPI envGetInetAddrConfigParam();
long epicsShareAPI envGetDoubleConfigParam();
long epicsShareAPI envGetLongConfigParam();
char * epicsShareAPI envGetConfigParamPtr();
#endif

#ifdef __cplusplus
}
#endif

#endif /*envDefsH*/

