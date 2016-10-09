#include "particlesource.h"
#include "particlecollection.h"
#include "explosionparticle.h"
#include "qwidgetrenderer.h"
#include <memory>
#include <QApplication>
#include <QWidget>
#include <QThread>
#include <QMutex>

int main(int argc, char *argv[])
{

    QMutex lock;
    QApplication app(argc, argv);

    QWidget window;
    std::unique_ptr<ParticleCollection> explosion(new ParticleCollection());
    ParticleSource<ExplosionParticle> source(explosion.get(), {290, 290, 0}, {310, 310, 0});
    QWidgetRenderer renderer(&window);
    explosion->render(&renderer);


    QThread* thread1 = new QThread;
    QObject::connect(thread1, &QThread::started, [&](){
        for(int i=0; i<100; i++) {
            lock.lock();
            explosion->addParticle(source.next());
            lock.unlock();
        }
        QThread::msleep(400);
        for(int i=0; i<500; i++) {
            lock.lock();
            explosion->addParticle(source.next());
            lock.unlock();
        }
    });

    QThread* thread2 = new QThread;
    QObject::connect(thread2, &QThread::started, [&](){
        while(true) {
            lock.lock();
            explosion->interact();
            lock.unlock();
            QThread::msleep(100);
        }
    });

    QThread* thread3 = new QThread;
    QObject::connect(thread3, &QThread::started, [&](){
        while(true) {
            lock.lock();
            explosion->update();
            lock.unlock();
            QThread::msleep(10);
        }
    });

    thread1->start();
    thread2->start();
    thread3->start();

    return app.exec();
}
