/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */
#include "../includes/scheduler_RR.h"


//override base class behaviour if necessary, otherwise call it
bool  Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p){
	sort();
	return (p.remaining_cpu_time <= 0 || (p.required_cpu_time - p.remaining_cpu_time) % time_slice == 0);
}
//RR - preemptive - no sorting of ready_q needed.
void Scheduler_RR::sort(){
	preemptive = true;
}


