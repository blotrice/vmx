/******************************************************************************
*   DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS HEADER.
*
*   This file is part of Real VMX.
*   Copyright (C) 2008 Surplus Users Ham Society
*
*   Real VMX is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   Real VMX is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with Real VMX.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

/* taskLib.h - Task scheduling library */

#ifndef _taskLib_h
#define _taskLib_h

#define WAIT_NONE			0x0
#define WAIT_FOREVER			0xffffffff

#define TASK_READY      		0x00
#define TASK_SUSPEND    		0x01
#define TASK_PEND       		0x02
#define TASK_DELAY      		0x04
#define TASK_DEAD       		0x08

#define NUM_TASK_PRIORITIES		256
#define MAX_TASK_NAME_LEN		256
#define MAX_TASK_DELAY			0xffffffff
#define DEFAULT_STACK_SIZE		0x1000

#define MAX_TASK_ARGS			10

#define TASK_UNDELAYED			2
#define TASK_DELETED			3

#define TASK_OPTIONS_DEALLOC_STACK	0x01

#ifndef _ASMLANGUAGE

#ifdef __cplusplus
extern "C" {
#endif

#include <arch/regs.h>
#include <vmx/classLib.h>
#include <vmx/objLib.h>
#include <vmx/semLib.h>
#include <util/qLib.h>

/* Task control block */
typedef struct taskTCB {

  /* Queues for sheduler */
  Q_HEAD qNode;				/* 0x00 */
  Q_HEAD tickNode;			/* 0x10 */
  Q_HEAD activeNode;			/* 0x20 */

  /* Stack */
  char *pStackBase;			/* 0x30 */
  char *pStackLimit;			/* 0x34 */

  /* Registers */
  REG_SET regs;				/* 0x38 */

  /* Entry point */
  FUNCPTR entry;			/* 0x60 */

  /* Errno */
  int errno;				/* 0x64 */

  /* Status */
  unsigned id;				/* 0x68 */
  unsigned status;			/* 0x6c */
  unsigned lockCount;			/* 0x70 */

  char name[MAX_TASK_NAME_LEN];
  unsigned stackDepth;
  unsigned priority;
  int options;
  unsigned priorityNormal;
  unsigned priorityMutexCount;
  SEM_ID priorityMutex;

  /* Timing */
  unsigned timeSlice;

  /* Used with semaphores */
  Q_HEAD *pPendQ;

  /* Safety */
  unsigned safeCount;
  Q_HEAD safetyQ;

  /* Error codes */
  int errorStatus;
  int exitCode;

  /* Class */
  OBJ_CORE objCore;

} __attribute__((packed)) TCB;

/* Macros */

/*******************************************************************************
* TASK_ID_VERIFY - Verify that this is a task object
*
* RETURNS: OK or ERROR
*******************************************************************************/

#define TASK_ID_VERIFY(tcbId)						       \
    (OBJ_VERIFY(tcbId, taskClassId))

typedef TCB *TCB_ID;
CLASS_ID taskClassId;

extern STATUS taskLibInit(void);
extern TCB_ID taskSpawn(const char *name,
                         unsigned priority,
			 int options,
                         unsigned stackDepth,
		         FUNCPTR func,
			 ARG arg0,
			 ARG arg1,
			 ARG arg2,
			 ARG arg3,
			 ARG arg4,
			 ARG arg5,
			 ARG arg6,
			 ARG arg7,
			 ARG arg8,
			 ARG arg9);
extern TCB_ID taskCreate(const char *name,
                         unsigned priority,
			 int options,
                         unsigned stackDepth,
		         FUNCPTR func,
			 ARG arg0,
			 ARG arg1,
			 ARG arg2,
			 ARG arg3,
			 ARG arg4,
			 ARG arg5,
			 ARG arg6,
			 ARG arg7,
			 ARG arg8,
			 ARG arg9);
extern STATUS taskInit(TCB_ID pTcb,
                       const char *name,
                       unsigned priority,
		       int options,
		       char *pStackBase,
                       unsigned stackDepth,
		       FUNCPTR func,
		       ARG arg0,
		       ARG arg1,
		       ARG arg2,
		       ARG arg3,
		       ARG arg4,
		       ARG arg5,
		       ARG arg6,
		       ARG arg7,
		       ARG arg8,
		       ARG arg9);
extern STATUS taskDelete(TCB_ID pTcb);
extern STATUS taskDeleteForce(TCB_ID pTcb);
extern STATUS taskTerminate(TCB_ID pTcb);
extern STATUS taskDestroy(TCB_ID pTcb,
                   	  BOOL freeStack,
                   	  unsigned timeout,
  	             	  BOOL forceDestroy);
extern STATUS taskActivate(TCB_ID pTcb);
extern STATUS taskSuspend(TCB_ID pTcb);
extern STATUS taskResume(TCB_ID pTcb);
extern STATUS taskDelay(unsigned timeout);
extern STATUS taskUndelay(TCB_ID pTcb);
extern STATUS taskPrioritySet(TCB_ID pTcb, unsigned priority);
extern STATUS taskPriorityGet(TCB_ID pTcb, unsigned *priority);
extern STATUS taskRestart(TCB_ID pTcb);
extern void taskExit(int code);
extern STATUS taskLock(void);
extern STATUS taskUnlock(void);
extern STATUS taskSafe(void);
extern STATUS taskUnsafe(void);
extern TCB_ID taskIdSelf(void);
extern TCB_ID taskTcb(TCB_ID pTcb);
extern void *taskStackAllot(TCB_ID pTcb, unsigned size);
extern STATUS taskIdVerify(TCB_ID pTcb);
extern int taskIdle(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _ASMLANGUAGE */

#endif /* _taskLib_h */
