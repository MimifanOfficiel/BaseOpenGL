// Struct for RGB values
struct Color {
    float r;
    float g;
    float b;
};

// Enumération des couleurs
enum class Colors {
    Red,
    Green,
    Blue,
    Yellow,
    White,
    Black,
    Cyan,
    Magenta,
    Gray,
    DarkGray,
    LightGray,
    Orange,
    Pink,
    Purple,
    Brown,
    Indigo,
    Teal,
    Lime,
    Olive,
    Maroon,
    Coral,
    Salmon,
    Gold,
    Silver,
    Turquoise,
    Peach,
    Beige
};

// Method to get the RGB component of a Color
Color getColor(Colors color) {
    switch (color) {
        case Colors::Red:         return {1.0f, 0.0f, 0.0f};
        case Colors::Green:       return {0.0f, 1.0f, 0.0f};
        case Colors::Blue:        return {0.0f, 0.0f, 1.0f};
        case Colors::Yellow:      return {1.0f, 1.0f, 0.0f};
        case Colors::White:       return {1.0f, 1.0f, 1.0f};
        case Colors::Black:       return {0.0f, 0.0f, 0.0f};
        case Colors::Cyan:        return {0.0f, 1.0f, 1.0f};
        case Colors::Magenta:     return {1.0f, 0.0f, 1.0f};
        case Colors::Gray:        return {0.5f, 0.5f, 0.5f};
        case Colors::DarkGray:    return {0.3f, 0.3f, 0.3f};
        case Colors::LightGray:   return {0.8f, 0.8f, 0.8f};
        case Colors::Orange:      return {1.0f, 0.65f, 0.0f};
        case Colors::Pink:        return {1.0f, 0.75f, 0.8f};
        case Colors::Purple:      return {0.5f, 0.0f, 0.5f};
        case Colors::Brown:       return {0.65f, 0.16f, 0.16f};
        case Colors::Indigo:      return {0.29f, 0.0f, 0.51f};
        case Colors::Teal:        return {0.0f, 0.5f, 0.5f};
        case Colors::Lime:        return {0.0f, 1.0f, 0.0f};
        case Colors::Olive:       return {0.5f, 0.5f, 0.0f};
        case Colors::Maroon:      return {0.5f, 0.0f, 0.0f};
        case Colors::Coral:       return {1.0f, 0.5f, 0.31f};
        case Colors::Salmon:      return {0.98f, 0.5f, 0.45f};
        case Colors::Gold:        return {1.0f, 0.84f, 0.0f};
        case Colors::Silver:      return {0.75f, 0.75f, 0.75f};
        case Colors::Turquoise:   return {0.25f, 0.88f, 0.82f};
        case Colors::Peach:       return {1.0f, 0.85f, 0.73f};
        case Colors::Beige:       return {0.96f, 0.96f, 0.86f};
        default:                 return {0.0f, 0.0f, 0.0f}; // Valeur par défaut
    }
}

