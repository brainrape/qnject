#include<fstream>
#include "vaccine.h"

int main(int argc, char ** argv) {
  const char * filename = "swagger.json";

  if (argc > 1)
    filename = argv[1];

  vaccine::wait_until_vaccine_is_running(10000);

  std::ofstream output(filename);
  output << std::setw(2) << vaccine::swagger_json() << std::endl;

  return(0);
}
