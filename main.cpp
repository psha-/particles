#include "particlesource.h"
#include "explosion.h"
#include "explosionparticle.h"
#include "qwidgetrenderer.h"
#include "interestingenvironment.h"
#include "fluidenvironment.h"
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
    QWidgetRenderer renderer(&window);
    FluidEnvironment environment = FluidEnvironment();
    std::unique_ptr<ParticleCollection<ExplosionParticle>> explosion(new Explosion(&environment));
    ParticleSource<ExplosionParticle> source(&renderer, explosion.get(), {290, 290, 0}, {310, 310, 0});

    QThread* thread1 = new QThread;
    QObject::connect(thread1, &QThread::started, [&](){
        for(int i=0; i<200; i++) {
            lock.lock();
            explosion->addParticle(source.next());
            lock.unlock();
        }
        QThread::msleep(700);
        for(int i=0; i<600; i++) {
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
            QThread::msleep(300);
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
