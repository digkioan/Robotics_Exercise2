#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

double radians_to_degrees(double radians) {
    return radians * 180.0 / PI;
}

double degrees_to_radians(double degrees) {
    return degrees * PI / 180.0;
}

double normalize_angle(double angle) {
    while (angle > 180.0) angle -= 360.0;
    while (angle < -180.0) angle += 360.0;
    return angle;
}

int main() {
    double rx, ry, ra;  // Ρομπότ: (x, y, γωνία σε μοίρες)
    double gx, gy;      // Στόχος: (x, y)

    // Διάβασμα δεδομένων εισόδου
    scanf("%lf %lf %lf %lf %lf", &rx, &ry, &ra, &gx, &gy);

    // Υπολογισμός απόστασης
    double dx = gx - rx;
    double dy = gy - ry;
    double distance = sqrt(dx * dx + dy * dy);

    // Υπολογισμός γωνίας προς τον στόχο (σε μοίρες)
    double target_angle = radians_to_degrees(atan2(dy, dx));

    // Υπολογισμός γωνίας περιστροφής
    double rotation_angle = normalize_angle(target_angle - ra);

    // Εκτύπωση αποτελεσμάτων (απόσταση και γωνία, με ένα κενό μεταξύ τους)
    printf("%.1lf %.1lf\n", distance, rotation_angle);

    return 0;
}