#include <QString>
#ifndef QUERIES_H
#define QUERIES_H







/*


QString insert_mammal_text =
        "INSERT INTO Mammal"
        "("
        "    identifier, "
        "    name,"
        "    age,"
        "    sex,"
        "    fk_l_a_id, "
        "    fk_c_id, "
        "    fk_v_id,"
        "    fk_r_n_id,"
        "    fk_r_t_id "
        ")"
        "VALUES "
        "("
        "    :identifier,"
        "    :name,"
        "    :age,"
        "    :sex,"
        "    SELECT living_area_id FROM LivingArea "
        "      WHERE living_area_name = :living_area_name "
        "      AND living_area_charactetistic = :living_area_charactetistic,"
        "    SELECT caretaker_id FROM Caretaker "
        "      WHERE full_name = :caretaker_full_name,"
        "    SELECT veterinarian_id FROM Veterinarian"
        "      WHERE full_name = :veterinarian_full_name,"
        "    SELECT ration_id FROM Ration "
        "      WHERE ration_name  = :ration_name,"
        "    SELECT ration_type_id FROM RationType "
        "      WHERE ration_type_name  = :ration_type_name "
        ");"
        ;

QString insert_reptile_text =
        "INSERT INTO Reptile"
        "("
        "    identifier, "
        "    name,"
        "    age,"
        "    sex,"
        "    avarage_temperature,"
        "    wintering_start_date,"
        "    wintering_end_date,"
        "    fk_l_a_id, "
        "    fk_c_id, "
        "    fk_v_id,"
        "    fk_r_n_id,"
        "    fk_r_t_id "
        ")"
        "VALUES "
        "("
        "    :identifier,"
        "    :name,"
        "    :age,"
        "    :sex,"
        "    SELECT living_area_id FROM LivingArea "
        "      WHERE living_area_name = :living_area_name"
        "      AND living_area_charactetistic = :living_area_charactetistic,"
        "    SELECT caretaker_id FROM Caretaker "
        "      WHERE full_name = :caretaker_full_name,"
        "    SELECT veterinarian_id FROM Veterinarian"
        "      WHERE full_name = :veterinarian_full_name,"
        "    SELECT ration_id FROM Ration "
        "      WHERE ration_name  = :ration_name,"
        "    SELECT ration_type_id FROM RationType "
        "      WHERE ration_type_name  = :ration_type_name"
        ");"
        ;

QString insert_veterinarian_text =
        "INSERT INTO Veterinarian("
        "    full_name,"
        "    phone_number,"
        "    date_of_birth"
        ")"
        "VALUES ("
        "    :full_name,"
        "    :phone_number,"
        "    :date_of_birth"
        ");"
        ;

QString insert_caretaker_text =
        "INSERT INTO Caretaker ("
        "    full_name,"
        "    phone_number,"
        "    date_of_birth"
        ")"
        "VALUES ("
        "    :full_name,"
        "    :phone_number,"
        "    :date_of_birth"
        ");"
        ;



QString update_mammal_text =
        "UPDATE Mammal "
        ""
        "    SET "
        "      name = :name,"
        "      age = :age,"
        "      sex = :sex,"
        "      fk_l_a_id = "
        "      (SELECT living_area_id FROM LivingArea"
        "        WHERE living_area_name = :living_area_name"
        "        AND living_area_characteristic = :living_area_characteristic),"
        "      fk_e_c_id = "
        "      (SELECT caretaker_id FROM Caretaker "
        "        WHERE full_name = :caretaker_fn),"
        "      fk_e_v_id = "
        "      (SELECT veterinarian_id FROM Veterinarian"
        "        WHERE full_name = :veterinarian_fn),"
        "      fk_r_n_id = "
        "      (SELECT ration_id FROM Ration "
        "        WHERE ration_name = :ration_name),"
        "      fk_r_t_id = "
        "      (SELECT ration_type_id FROM RationType "
        "        WHERE ration_type_name = :ration_type_name)"
        "    WHERE identifier = :identifier"
        ";"
        ;

QString update_reptile_text =
        "UPDATE Reptile "
        ""
        "    SET "
        "      name = :name,"
        "      age = :age,"
        "      sex = :sex,"
        "      avarage_temperature = :avarage_temperature,"
        "      wintering_start_date = :wintering_start_date,"
        "      wintering_end_date = : wintering_end_date,"
        "      fk_l_a_id = "
        "      (SELECT living_area_id FROM LivingArea"
        "        WHERE living_area_name = :living_area_name"
        "        AND living_area_characteristic = :living_area_characteristic),"
        "      fk_e_c_id = "
        "      (SELECT caretaker_id FROM Caretaker"
        "        WHERE full_name = :caretaker_fn),"
        "      fk_e_v_id = "
        "      (SELECT veterinarian_id FROM Veterinarian "
        "        WHERE full_name = :veterinarian_fn),"
        "      fk_r_n_id = "
        "      (SELECT ration_id FROM Ration "
        "        WHERE ration_name = :ration_name),"
        "      fk_r_t_id = "
        "      (SELECT ration_type_id FROM RationType"
        "        WHERE ration_type_name = :ration_type_name)"
        ""
        "    WHERE identifier = :identifier"
        ";"
        ;

QString update_caretaker_text =
        "UPDATE Caretaker"
        "    SET "
        "      full_name = :caretaker_name,"
        "      phone_number = :phone_number,"
        "      date_of_birth = :date_of_birth"
        "    WHERE caretaker_id = :caretaker_id;"
        ;

QString update_veterinarian_text =
        "UPDATE Veterinarian "
        "    SET "
        "      full_name = :caretaker_name,"
        "      phone_number = :phone_number,"
        "      date_of_birth = :date_of_birth"
        "    WHERE veterinarian_id = :veterinarian_id;"
        ;


QString select_bird =
        "SELECT B.name, B.age, "
        "B.country_code, B.country_name, B.start_date,"
        "B.end_date, B.sex,"
        ""
        "LA.living_area_name, LA.living_area_characteristic,"
        "C.full_name,"
        "V.full_name,"
        "R.ration_name,"
        "RT.ration_type_name"
        "FROM Bird AS B"
        "JOIN LivingArea AS LA "
        "ON LA.living_area_id = B.fk_l_a_id"
        "JOIN Caretaker AS C"
        "ON C.caretaker_id = B.fk_e_c_id"
        "JOIN Veterinarian AS V"
        "ON V.veterinarian_id = B.fk_e_v_id"
        "JOIN Ration AS R"
        "ON R.ration_id = B.fk_r_n_id"
        "JOIN RationType AS RT"
        "ON RT.ration_type_id = B.fk_r_t_id"
        "WHERE B.identifier = :identifier;"
        ;
*/
#endif // QUERIES_H
