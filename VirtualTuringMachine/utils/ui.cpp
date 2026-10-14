#include "ui.h"

#include "VMTJsonSerializer.h"
#include "uistatenewproject.h"

namespace utils::ui {
QChar escapeChar(QChar c) {
    if (c == QChar(' ')) {
        return QChar(L'λ');
    }
    return c;
}
QString escapeString(const QString& s) {
    QString result;
    result.reserve(s.size());
    for (QChar c : s) {
        result.push_back(escapeChar(c));
    }
    return result;
}
bool SerializeWithPromptIfNeeded() {
    QString file_path;
    UIStateNewProject::GetProjectFileName(file_path);
    VMTJsonSerializer serializer{file_path};
    auto& project = VMTProject::GetInstance();
    if (!project.GetMachines().empty() && serializer.serialize(&project)) {
        Configuration::GetInstance().AddRecentProject(file_path);
        Configuration::GetInstance().Save();
        QMessageBox box;
        box.setText("Project saved");
        box.exec();
        return true;
    }
    return false;
}
}  // namespace utils::ui
