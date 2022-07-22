#include <iostream>
#include <exception>
#include "vtkPolyDataReader.h"
#include "vtkPolyDataWriter.h"
#include "vtkPolyData.h"

using namespace std;

int main(int argc, char *argv[])
{
  if ((argc == 1 && strcmp(argv[1], "-h") == 0) || argc < 4)
    {
    std::cerr << std::endl;
    std::cerr << "====================================" << std::endl;
    std::cerr << "  VTKConverter " << std::endl;
    std::cerr << "====================================" << std::endl << std::endl;
    std::cerr << "Convert a vtk legacy polydata (.vtk) input file to a polydata file "
              << "with specified target version" << std::endl << std::endl;
    std::cerr << "Usage: VTKConverter targetVersion input.vtk output.vtk" << std::endl;
    std::cerr << "-- TargetVersion: 42 for version 4.2 (default) or 51 for version 5.1" << std::endl;
    std::cerr << "-- If input file is already in target version, converter will still write an"
              << " output file with the target version in the output filt path" << std::endl;
    std::cerr << std::endl << std::endl;
    return EXIT_FAILURE;
    }

  int targetVersion = -1;

  targetVersion = atoi(argv[1]);

  if (targetVersion != 42 && targetVersion != 51)
    {
    std::cerr << "Invalid targetVersion input (" << argv[1] << "). TargetVersion can only be 42 or 51" << std::endl;
    return EXIT_FAILURE;
    }

  const char* fninput = argv[2];
  const char* fnoutput = argv[3];


  vtkNew<vtkPolyDataReader> reader;
  reader->SetFileName(fninput);
  reader->Update();

  vtkNew<vtkPolyDataWriter> writer;
  writer->SetFileName(fnoutput);
  writer->SetInputData(reader->GetOutput());
  writer->SetFileVersion(targetVersion);
  writer->Write();

  return EXIT_SUCCESS;
}
