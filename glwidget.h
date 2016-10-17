#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <vector>
#include <QOpenGLWidget>

class Renderable;
class PaintHelper;

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    GLWidget(PaintHelper *paintHelper, QWidget *parent, std::vector<Renderable*>* renderables);

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    PaintHelper *_paintHelper;
    std::vector<Renderable*>* _renderables;

};

#endif
