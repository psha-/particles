#include "particlesource.h"
#include "particlecollection.h"
#include "explosionparticle.h"
#include "qwidgetrenderer.h"
#include <memory>
#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QWidget window;
    std::unique_ptr<ParticleCollection> explosion(new ParticleCollection());
    ParticleSource<ExplosionParticle> source(explosion.get(), {180, 200, 0}, {220, 240, 0});

    for(int i=0; i<100; i++) {
        explosion->addParticle(source.next());
    }

    QWidgetRenderer renderer(&window);
    explosion->render(&renderer);

    return app.exec();
}
