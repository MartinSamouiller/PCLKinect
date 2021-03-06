#ifndef ICPTHREAD_H
#define ICPTHREAD_H

#include <QThread>
#include <QString>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <eigen3/Eigen/Eigen>
/*
 * CLASSE DE REGISTRATION PAR ICP
 * Lancé sur un thread séparé pour ne pas freezer l'IHM
 * */


using namespace pcl;
using namespace std;

typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloudT;


class icpthread : public QThread
{
     Q_OBJECT

signals:
    void icpFinish() ;

public:
    icpthread();
    void
    init(PointCloudT::Ptr cloudSource, PointCloudT::Ptr cloudTarget);
    void
    getFinishCloud(PointCloudT::Ptr cloudResult);
    void
    createMsgError(QString msg);

    void
    run();

    QString
    print4x4Matrix (const Eigen::Matrix4d & matrix);

private:
    PointCloudT::Ptr _cloudSource;
    PointCloudT::Ptr _cloudTarget;
    PointCloudT::Ptr  _finalCloud;
    QString _message;
};

#endif // ICPTHREAD_H
