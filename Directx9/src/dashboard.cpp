#include "dashboard.h"

void createWindow() {
	ImGui::Begin("New Window");
	ImGui::Text("Dashboard ");
	ImGui::End();
}

static void DrawRadialGauge(ImDrawList* draw_list, ImVec2 center, float radius, float value, float min_value, float max_value, ImU32 color) {
    // Ensure value is within range
    
    float angle_start = PI * 1.5f;  // Start angle in radians (3 o'clock position)
    float angle_end = angle_start + (2 * PI * (value - min_value) / (max_value - min_value));

    // Draw background circle
    draw_list->AddCircle(center, radius, IM_COL32(100, 100, 100, 255), 32);
    
    // Draw gauge arc
    draw_list->PathArcTo(center, radius, angle_start, angle_end, 32);
    draw_list->PathStroke(color, false, 5.0f);  // Stroke thickness

    // Optionally, draw a center point or indicator
    // draw_list->AddCircle(center, 5.0f, IM_COL32(255, 255, 255, 255));
}

// Usage in your ImGui rendering function
void RenderUI() {
    ImGui::Begin("Radial Gauge Example");

    ImVec2 window_size = ImGui::GetWindowSize();
    ImVec2 center;
    center.x = ImGui::GetWindowPos().x + window_size.x * 0.5f;
    center.y = ImGui::GetWindowPos().y + window_size.y * 0.5f;
    float radius = 100.0f;
    float value = 70.0f;   // Example value
    float min_value = 0.0f;
    float max_value = 100.0f;
    ImU32 gauge_color = IM_COL32(0, 255, 0, 255);  // Green

    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    DrawRadialGauge(draw_list, center, radius, value, min_value, max_value, gauge_color);

    ImGui::End();
}
