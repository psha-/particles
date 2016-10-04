#include "particlecollection.h"
#include "qwidgetrenderer.h"
#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    Renderable* particles = new ParticleCollection({
                                                       new Particle({10,10,10}, {0.1,0,0}, {0,0.02,0}),
                                                       new Particle({10,10,10}, {0.1,0.1,0}, {0,0.05,0}),
                                                       new Particle({10,10,10}, {0.5,0.3,0}, {0.01,0.02,0}),
                });
    QWidgetRenderer renderer(&window);
    particles->render(&renderer);
    renderer.start();

    return app.exec();
}
