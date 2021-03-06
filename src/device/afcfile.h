#ifndef AFCFILE_H
#define AFCFILE_H

#include "config.h"

#include <stdint.h>
#include <libimobiledevice/afc.h>

#include <QtGlobal>
#include <QObject>
#include <QIODevice>
#include <QString>

class iMobileDeviceConnection;

class AfcFile : public QIODevice {
  Q_OBJECT

public:
  AfcFile(iMobileDeviceConnection* connection, const QString &path, QObject *parent = 0);
  ~AfcFile();

  // QIODevice
  void close();
  bool open(OpenMode mode);
  bool seek(qint64 pos);
  qint64 size() const;

private:
  // QIODevice
  qint64 readData(char *data, qint64 max_size);
  qint64 writeData(const char *data, qint64 max_size);

  iMobileDeviceConnection *connection_;
  uint64_t handle_;

  QString path_;
};

#endif
