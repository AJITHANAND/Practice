


SELECT IF(GRADE<8,'NULL',NAME),MARKS,GRADE
FROM (
    SELECT NAME, MARKS , IF(MARKS>=90,10,
        IF(MARKS>=80,9,
            IF(MARKS>=70,8,
                IF(MARKS>=60,7,
                    IF(MARKS>=50,6,
                        IF(MARKS>=40,5,
                            IF(MARKS >=30,4,
                                IF(MARKS >=20,3,
                                    IF(MARKS >=10,2,
                                        IF(MARKS >=0,1,0)
                                    )
                                )
                            )
                        )
                    )
                )
            )
        )
    ) AS GRADE
    FROM STUDENTS
)
ORDER BY GRADE DESC , NAME ASC;