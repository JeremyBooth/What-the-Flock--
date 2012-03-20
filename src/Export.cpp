//----------------------------------------------------------------------------------------------------------------------
/// @file Export.cpp
/// @brief The class writes the aniamted pointcloud data to a file
//----------------------------------------------------------------------------------------------------------------------

#include "Export.h"
//#include "BoidManager.h"
#include <QFile>
#include <iostream>
#include <fstream>


//----------------------------------------------------------------------------------------------------------------------
Export::Export()
{
  std::ofstream exportFile;
  exportFile.open("batty.txt");
  //exportFile<<"shank!!!"<<std::endl;
}



void Export::writeFile()

{
  //int count;
  //++count;

  //exportFile.open("batty.txt");

  //m_flock
  std::cout<<"shank"<<std::endl;

  //exportFile << count << std::endl;

  //exportFile.close();

  //file = ("shank.txt");

  /*QFile file("out.txt");
  if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Append))
         return;

     // m_flock->getList();

      std::cout<<"shank2"<<std::endl;
     QTextStream out(&file);
      std::cout<<"shank3"<<std::endl;
     //BoidManager::getList();
      //size = m_boids->getList();*/


    /* for(int i=0; i<m_boids->getList().size(); ++i)
     {
       std::cout<<"shank4"<<std::endl;
       //ngl::Vector shank(0,0,0);


       //out << m_boids->getList()[i].m_pos << "\n";
      //out << shank[1] << "\n";
      out << "The magic number is: " << 49 << "\n";
     }*/

}




void Export::clearFile()
{

  QFile file("out.txt");
  if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
         return;

     QTextStream out(&file);
     out << "";
     file.close();

}


