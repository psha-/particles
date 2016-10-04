#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "renderable.h"
#include <vector>
#include <QOpenGLWidget>

class Helper;

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    GLWidget(Helper *helper, QWidget *parent, std::vector<Renderable*>* renderables);

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    Helper *helper;
    std::vector<Renderable*>* _renderables;

};

#endif
