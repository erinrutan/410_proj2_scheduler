/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */
#include "../includes/scheduler_SRTF.h"
#include "../includes/PCB.h"
#include "../includes/constants.h"
#include <queue>
#include <algorithm>

using namespace std;

//override base class behaviour if necessary, otherwise call it
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p){
	sort();
	return Scheduler::time_to_switch_processes(tick_count, p);
}

//sort helper
bool sort_helper(PCB i, PCB j) {
	return (i.remaining_cpu_time < j.remaining_cpu_time);
}

//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort(){
	preemptive = true;
	//take everything out of queue to sort
	std::vector<PCB> rq;
	while (!ready_q->empty()) {
		rq.push_back(ready_q->front());
		ready_q->pop();
	}

	//sort!
	std::sort(rq.begin(),rq.end(), sort_helper);


	//push sorted processes back into queue
	for (int i = 0; i < rq.size(); i++) {
		ready_q->push(rq.at(i));
	}

}

