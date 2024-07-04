#include <auroraapp.h>
#include <QtQuick>
#include <QtQml>
#include "modelinfo.h"
#include "stringobject.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<ModelInfo>("ru.bmstu.MobAdaptUi", 1, 0, "ModelInfo"); //----second way CPPtoQML
    qmlRegisterType<StringObject>("ru.bmstu.MobAdaptUi", 1, 0, "StringObject");

    QScopedPointer<QGuiApplication> application(Aurora::Application::application(argc, argv));
    application->setOrganizationName(QStringLiteral("ru.bmstu"));
    application->setApplicationName(QStringLiteral("MobAdaptUiQmake"));

    QScopedPointer<QQuickView> view(Aurora::Application::createView());
    view->setSource(Aurora::Application::pathTo(QStringLiteral("qml/MobAdaptUiQmake.qml")));

    //----first way CPPtoQML
//    auto stringObject = new StringObject(application.data());
//    view->rootContext()->setContextProperty("stringObject", stringObject);

    view->show();

    return application->exec();
}
