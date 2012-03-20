#ifndef _EXPORT_H__
#define _EXPORT_H__

#include <fstream>
#include <QFile>
#include <QString>
#include <QTextStream>
#include "BoidManager.h"

/// @file Export.h
/// @brief The class that exports the animation data
/// @author Jeremy Booth
/// @version 1.0
/// @date 9/4/12
/// Revision History :
/// Initial Version 9/4/11
/// @class Export
/// @brief Writing out the pointcloud data to a file
///
class Export
{
public:

  /// @brief ctor
  Export();

 void writeFile();
 void clearFile();


private:
 std::fstream exportFile;
int count;
int size;
QFile file;
QString text;
BoidManager *m_flock;




};

#endif
