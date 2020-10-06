/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */
#include "../includes/stats.h"
#include "../includes/constants.h"
#include "../includes/PCB.h"

using namespace std;

Stats::Stats(std::vector<PCB> &finished_vector){
	vec = &finished_vector;
	av_turnaround_time = 0.0;
	av_response_time = 0.0;
	av_wait_time = 0.0;
	calcStats();
}

//loops thru vec, prints 1 line for each process using the following format
//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
//if there are 10 processes in vector, should print 10 lines
void Stats::showAllProcessInfo() {
	for (int i = 0; i < vec->size(); i++) {
		cout << "Process " + to_string(i) + " required CPU time:" +
				to_string(vec->at(i).required_cpu_time) + " arrived:" +
				to_string(vec->at(i).arrival_time) + " started:" +
				to_string(vec->at(i).start_time) +
				" finished:" + to_string(vec->at(i).finish_time) << endl;
	}
}

//after a process is placed in the ready_q, how long does
//it take before its placed on the processor?
//response_time per process = start_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_response_time() {
	return av_response_time;
}

//after a process is placed in the ready_q, how long does
//it take to complete?
//turnaround time per process = finish_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_turnaround_time() {
	return av_turnaround_time;
}

//after a process is placed in the ready_q, how much time does it
//spend waiting for processor time?
//wait time per process = finish_time - arrival_time-required_CPU_time
//this funtion returns the average over all processes
float Stats::get_av_wait_time() {
	return av_wait_time;
}

//does the work (only needs to run once)
void Stats::calcStats(){
		float total_response_time = 0.0;
		float total_turnaround_time = 0.0;
		float total_wait_time = 0.0;

		for (PCB process : *vec) {
			total_response_time += process.start_time - process.arrival_time;
			total_turnaround_time += process.finish_time - process.arrival_time;
			total_wait_time += process.finish_time - process.arrival_time - process.required_cpu_time;
		}

		int s = vec->size();
		av_response_time = total_response_time / s;
		av_turnaround_time = total_turnaround_time / s;
		av_wait_time = total_wait_time / s;
}

