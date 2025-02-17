#pragma once  // Header guard see https://en.wikipedia.org/wiki/Include_guard

// Copyright (c) 2023 Sri Lakshmi Kanthan P
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include <QPushButton>

namespace srilakshmikanthanp::clipbirdesk::ui::gui::components {
class Button : public QPushButton {
 private:  // Constants

  static constexpr const char *const style = R"(
  )";

 private:  // just for Qt

  Q_OBJECT

 public:

  /**
   * @brief Construct a new Button object
   * with parent as QButton
   * @param parent parent object
   */
  explicit Button(QWidget *parent = nullptr);

  /**
   * @brief Destroy the Button object
   * with virtual destructor
   */
  ~Button() override = default;

 private:  // disable copy and move

  Q_DISABLE_COPY_MOVE(Button)
};
}  // namespace srilakshmikanthanp::clipbirdesk::ui::gui::components
