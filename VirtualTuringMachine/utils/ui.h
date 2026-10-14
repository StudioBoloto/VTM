#pragma once

#include <QChar>
#include <QString>

namespace utils::ui {

/**
 * @brief Change some chars to pretty render view

 * For example: ' ' -> 'λ'
 */
QChar escapeChar(QChar c);

/**
 * @brief Map escapeChar to all chars in string
 */
QString escapeString(const QString& s);

/**
 * @brief Serialize project if needed
 *
 * @return true if serialized happened, false otherwise,
 */
bool SerializeWithPromptIfNeeded();
}  // namespace utils::ui
