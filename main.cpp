#include<iostream>
#include<string>
#include <chrono>
#include "utils.hpp"         

using namespace std;

int main(int argc, char *argv[]) {
  int run;
  algorithm = argv[1];
  if (argv[2]){
    problem_instance = argv[2]; 
    read_problem(problem_instance);   //Read EVRP from file from EVRP.h
    cout << problem_instance << "\n";
  } else {
    cout << "Please specify a problem instance" << endl;
    return 0;
  }
  char* output_path;
  if (argv[3]){
    output_path = argv[3];
  } else {
    cout << "Please specify an output path" << endl;
    return 0;
  }
  open_stats(algorithm, output_path);//open text files to store the best values from the 20 runs stats.h
  cout << "Running " << MAX_TRIALS << " times" << endl;

  for(run = 1; run <= MAX_TRIALS; run++){
    start_run(run);
    auto start_time = std::chrono::high_resolution_clock::now();

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count();
    if (algorithm == "SACO"){
      SACO  *ANTS = new SACO (1, 2, 80, 0.1, 2, 0);
      while(!termination_condition(1)){
        ANTS->optimize();
      }
      save_solution(output_path, algorithm, problem_instance, run); 
      ANTS->free_SACO();
    } else if (algorithm == "GS"){
      initialize_GS();
      gs_optimizer.run(gs_optimizer.best_solution);
      save_solution(output_path, algorithm, problem_instance, run); 
      free_GS();
    } else if (algorithm == "HMAGS"){
      initialize_HMAGS();
//      while(!termination_condition(1)){
//        run_HMAGS();
//      }
      if(run == 1) open_stats_of_evolution(output_path, algorithm, problem_instance, run);
      while (!termination_condition_max_time(duration)) {
          run_HMAGS();
          end_time = std::chrono::high_resolution_clock::now();
          duration = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count();
          if (run == 1) stats_evols(duration, hmags);
      }
      save_solution(output_path, algorithm, problem_instance, run);
      free_HMAGS();
      if (run == 1) close_stats_of_evolution();
    } else if (algorithm == "SA"){
      initialize_SA();
      SA_optimizer.run(SA_optimizer.cur_sol);  
      save_solution(output_path, algorithm, problem_instance, run); 
      free_SA();
    } else{
      cout << "Algorithm " << algorithm << " not found" << endl;
    }
    end_run(run);  //store the best solution quality for each run
  }
  close_stats(); 
  return 0;
}
