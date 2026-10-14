#include "ui.h"

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
}  // namespace utils::ui
