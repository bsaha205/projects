/*
Navicat Oracle Data Transfer
Oracle Client Version : 10.2.0.5.0

Source Server         : newsms
Source Server Version : 110200
Source Host           : localhost:1521
Source Schema         : SMS

Target Server Type    : ORACLE
Target Server Version : 110200
File Encoding         : 65001

Date: 2015-12-22 23:04:45
*/


-- ----------------------------
-- Table structure for "SMS"."ADDRESSES"
-- ----------------------------
DROP TABLE "SMS"."ADDRESSES";
CREATE TABLE "SMS"."ADDRESSES" (
"ADDRESS_ID" NUMBER(10) NOT NULL ,
"HOUSE_NO" VARCHAR2(10 BYTE) NULL ,
"ROAD_NO" VARCHAR2(10 BYTE) NULL ,
"VILLAGE" VARCHAR2(15 BYTE) NULL ,
"POST_OFFICE" VARCHAR2(15 BYTE) NULL ,
"THANA" VARCHAR2(15 BYTE) NULL ,
"DISTRICT" VARCHAR2(15 BYTE) NULL ,
"STUDENT_ID" NUMBER(10) NULL ,
"TEACHER_ID" NUMBER(10) NULL 
)
LOGGING
NOCOMPRESS
NOCACHE

;

-- ----------------------------
-- Records of ADDRESSES
-- ----------------------------
INSERT INTO "SMS"."ADDRESSES" VALUES ('1', 'DSFDSF', 'DSFDS', 'dsfds', 'SDFD', 'DSF', 'DFDF', '1', null);

-- ----------------------------
-- Table structure for "SMS"."CLASS"
-- ----------------------------
DROP TABLE "SMS"."CLASS";
CREATE TABLE "SMS"."CLASS" (
"CLASS_ID" NUMBER(5) NOT NULL ,
"CLASS_NAME" VARCHAR2(10 BYTE) NOT NULL ,
"MONTHLY_FEE" NUMBER(5) NULL ,
"MONTHLY_FINE" NUMBER(5) NULL ,
"NO_OF_STUDENTS" NUMBER(5) NULL 
)
LOGGING
NOCOMPRESS
NOCACHE

;

-- ----------------------------
-- Records of CLASS
-- ----------------------------
INSERT INTO "SMS"."CLASS" VALUES ('8', 'EIGHT', '50', '15', null);
INSERT INTO "SMS"."CLASS" VALUES ('7', 'SEVEN', '40', '10', null);
INSERT INTO "SMS"."CLASS" VALUES ('6', 'SIX', '40', '10', '9');

-- ----------------------------
-- Table structure for "SMS"."FEES"
-- ----------------------------
DROP TABLE "SMS"."FEES";
CREATE TABLE "SMS"."FEES" (
"BILL_NO" NUMBER(10) NOT NULL ,
"PAYMENT_DATE" DATE NULL ,
"MONTH_PAID" NUMBER(15) NULL ,
"STUDENT_ID" NUMBER(10) NOT NULL ,
"DUE" NUMBER(5) NULL 
)
LOGGING
NOCOMPRESS
NOCACHE

;

-- ----------------------------
-- Records of FEES
-- ----------------------------
INSERT INTO "SMS"."FEES" VALUES ('1', TO_DATE('1999-07-07 00:00:00', 'YYYY-MM-DD HH24:MI:SS'), '7', '1', '250');

-- ----------------------------
-- Table structure for "SMS"."GENSUBJECT"
-- ----------------------------
DROP TABLE "SMS"."GENSUBJECT";
CREATE TABLE "SMS"."GENSUBJECT" (
"SUBJECT_ID" NUMBER(5) NOT NULL ,
"SUBJECT_NAME" VARCHAR2(20 BYTE) NOT NULL 
)
LOGGING
NOCOMPRESS
NOCACHE

;

-- ----------------------------
-- Records of GENSUBJECT
-- ----------------------------
INSERT INTO "SMS"."GENSUBJECT" VALUES ('1', 'GENERAL SCIENCE');
INSERT INTO "SMS"."GENSUBJECT" VALUES ('2', 'MATHEMATICS');
INSERT INTO "SMS"."GENSUBJECT" VALUES ('3', 'ENGLISH');
INSERT INTO "SMS"."GENSUBJECT" VALUES ('4', 'BANGLA');

-- ----------------------------
-- Table structure for "SMS"."GRADES"
-- ----------------------------
DROP TABLE "SMS"."GRADES";
CREATE TABLE "SMS"."GRADES" (
"GRADE_ID" NUMBER(10) NOT NULL ,
"GRADE_POINT" NUMBER(10,3) NOT NULL ,
"MERIT_POSITION" NUMBER(5) NOT NULL ,
"STUDENT_ID" NUMBER(10) NOT NULL ,
"CLASS_ID" NUMBER(5) NULL 
)
LOGGING
NOCOMPRESS
NOCACHE

;

-- ----------------------------
-- Records of GRADES
-- ----------------------------
INSERT INTO "SMS"."GRADES" VALUES ('1', '3.25', '1', '1', '6');

-- ----------------------------
-- Table structure for "SMS"."SECTION"
-- ----------------------------
DROP TABLE "SMS"."SECTION";
CREATE TABLE "SMS"."SECTION" (
"SECTION_ID" NUMBER(5) NOT NULL ,
"CLASS_ID" NUMBER(5) NOT NULL ,
"SECTION_NAME" VARCHAR2(10 BYTE) NOT NULL ,
"ROOM_NO" NUMBER(5) NULL ,
"NO_OF_STUDENTS" NUMBER(5) NULL 
)
LOGGING
NOCOMPRESS
NOCACHE

;

-- ----------------------------
-- Records of SECTION
-- ----------------------------
INSERT INTO "SMS"."SECTION" VALUES ('2', '6', 'B', '302', null);
INSERT INTO "SMS"."SECTION" VALUES ('1', '6', 'A', '301', null);

-- ----------------------------
-- Table structure for "SMS"."STUDENTS"
-- ----------------------------
DROP TABLE "SMS"."STUDENTS";
CREATE TABLE "SMS"."STUDENTS" (
"STUDENT_ID" NUMBER(10) NOT NULL ,
"FIRST_NAME" VARCHAR2(15 BYTE) NOT NULL ,
"LAST_NAME" VARCHAR2(15 BYTE) NOT NULL ,
"BIRTH_DATE" DATE NULL ,
"GENDER" VARCHAR2(8 BYTE) NULL ,
"SECTION_ID" NUMBER(5) NOT NULL ,
"CLASS_ID" NUMBER(5) NOT NULL ,
"ROLL" NUMBER(5) NULL 
)
LOGGING
NOCOMPRESS
NOCACHE

;

-- ----------------------------
-- Records of STUDENTS
-- ----------------------------
INSERT INTO "SMS"."STUDENTS" VALUES ('5', 'FG', 'DFSF', TO_DATE('1995-02-02 00:00:00', 'YYYY-MM-DD HH24:MI:SS'), 'SDFDF', '1', '6', '16');
INSERT INTO "SMS"."STUDENTS" VALUES ('6', 'ALU', 'LAM', TO_DATE('2014-07-07 00:00:00', 'YYYY-MM-DD HH24:MI:SS'), 'MALE', '1', '6', '44');
INSERT INTO "SMS"."STUDENTS" VALUES ('7', 'LAU', 'KODU', TO_DATE('2014-07-07 00:00:00', 'YYYY-MM-DD HH24:MI:SS'), 'FEMAL', '1', '6', '54');
INSERT INTO "SMS"."STUDENTS" VALUES ('3', 'FGF', 'FGF', TO_DATE('1999-07-07 00:00:00', 'YYYY-MM-DD HH24:MI:SS'), 'FGF', '1', '6', '14');
INSERT INTO "SMS"."STUDENTS" VALUES ('4', 'BATA', 'DFDF', TO_DATE('204-08-08 00:00:00', 'YYYY-MM-DD HH24:MI:SS'), 'DFD', '1', '6', '7');
INSERT INTO "SMS"."STUDENTS" VALUES ('2', 'MUSTAKIM', 'AHAD', TO_DATE('1999-07-07 00:00:00', 'YYYY-MM-DD HH24:MI:SS'), 'MALE', '1', '6', '10');
INSERT INTO "SMS"."STUDENTS" VALUES ('8', 'KUMRO', 'VAJI', TO_DATE('2012-08-08 00:00:00', 'YYYY-MM-DD HH24:MI:SS'), 'FEMALE', '1', '6', '5');
INSERT INTO "SMS"."STUDENTS" VALUES ('9', 'ABDUN', 'NOOR', TO_DATE('2014-07-07 00:00:00', 'YYYY-MM-DD HH24:MI:SS'), 'MALE', '1', '6', '3');
INSERT INTO "SMS"."STUDENTS" VALUES ('1', 'BISHWA', 'JIT', TO_DATE('1999-08-07 00:00:00', 'YYYY-MM-DD HH24:MI:SS'), 'FEMAL', '1', '6', '22');

-- ----------------------------
-- Table structure for "SMS"."SUBJECT"
-- ----------------------------
DROP TABLE "SMS"."SUBJECT";
CREATE TABLE "SMS"."SUBJECT" (
"SUBJECT_ID" NUMBER(5) NOT NULL ,
"SECTION_ID" NUMBER(5) NOT NULL ,
"CLASS_ID" NUMBER(5) NOT NULL ,
"SUBJECT_NAME" VARCHAR2(15 BYTE) NOT NULL ,
"CLASS_TIME" VARCHAR2(10 BYTE) NULL ,
"TEACHER_ID" NUMBER(10) NULL 
)
LOGGING
NOCOMPRESS
NOCACHE

;

-- ----------------------------
-- Records of SUBJECT
-- ----------------------------
INSERT INTO "SMS"."SUBJECT" VALUES ('4', '1', '6', 'BANGLA', '2', '1');

-- ----------------------------
-- Table structure for "SMS"."TEACHERS"
-- ----------------------------
DROP TABLE "SMS"."TEACHERS";
CREATE TABLE "SMS"."TEACHERS" (
"TEACHER_ID" NUMBER(10) NOT NULL ,
"FIRST_NAME" VARCHAR2(15 BYTE) NOT NULL ,
"LAST_NAME" VARCHAR2(15 BYTE) NOT NULL ,
"JOIN_DATE" DATE NOT NULL ,
"GENDER" VARCHAR2(8 BYTE) NOT NULL ,
"POSITION" VARCHAR2(20 BYTE) NOT NULL ,
"POS_VAL" NUMBER(5) NOT NULL 
)
LOGGING
NOCOMPRESS
NOCACHE

;

-- ----------------------------
-- Records of TEACHERS
-- ----------------------------
INSERT INTO "SMS"."TEACHERS" VALUES ('2', 'KHALID', 'HASAN', TO_DATE('2014-07-07 00:00:00', 'YYYY-MM-DD HH24:MI:SS'), 'MALE', 'ASSISTANT HEADMASTER', '0');
INSERT INTO "SMS"."TEACHERS" VALUES ('3', 'KHALID', 'RAI', TO_DATE('2013-07-08 00:00:00', 'YYYY-MM-DD HH24:MI:SS'), 'MALE', 'JUNIOR TEACHER', '5');
INSERT INTO "SMS"."TEACHERS" VALUES ('1', 'LATIF', 'HASAN', TO_DATE('2015-09-07 00:00:00', 'YYYY-MM-DD HH24:MI:SS'), 'MALE', 'TEACHER', '4');

-- ----------------------------
-- Table structure for "SMS"."USERS"
-- ----------------------------
DROP TABLE "SMS"."USERS";
CREATE TABLE "SMS"."USERS" (
"USERNAME" VARCHAR2(20 BYTE) NOT NULL ,
"PASSWORD" VARCHAR2(20 BYTE) NOT NULL 
)
LOGGING
NOCOMPRESS
NOCACHE

;

-- ----------------------------
-- Records of USERS
-- ----------------------------
INSERT INTO "SMS"."USERS" VALUES ('S', 'S');
INSERT INTO "SMS"."USERS" VALUES ('FIRST', 'FIRST');
INSERT INTO "SMS"."USERS" VALUES ('SECOND', 'SECOND');
INSERT INTO "SMS"."USERS" VALUES ('ADMIN', 'ADMIN');
INSERT INTO "SMS"."USERS" VALUES ('A', 'A');

-- ----------------------------
-- Function structure for "SMS"."MERIT_POS"
-- ----------------------------
CREATE OR REPLACE FUNCTION "SMS"."MERIT_POS" (ST_ID IN NUMBER, CL_ID IN NUMBER, GP IN FLOAT) RETURN NUMBER AS
MPOS NUMBER;
BEGIN
  SELECT COUNT(G1.STUDENT_ID) INTO MPOS
  FROM GRADES G1
  WHERE (GP<G1.GRADE_POINT AND CL_ID=G1.CLASS_ID);
  RETURN (MPOS);
END merit_pos;
/

-- ----------------------------
-- Indexes structure for table ADDRESSES
-- ----------------------------

-- ----------------------------
-- Uniques structure for table "SMS"."ADDRESSES"
-- ----------------------------
ALTER TABLE "SMS"."ADDRESSES" ADD UNIQUE ("STUDENT_ID");
ALTER TABLE "SMS"."ADDRESSES" ADD UNIQUE ("TEACHER_ID");

-- ----------------------------
-- Checks structure for table "SMS"."ADDRESSES"
-- ----------------------------
ALTER TABLE "SMS"."ADDRESSES" ADD CHECK ("ADDRESS_ID" IS NOT NULL);

-- ----------------------------
-- Primary Key structure for table "SMS"."ADDRESSES"
-- ----------------------------
ALTER TABLE "SMS"."ADDRESSES" ADD PRIMARY KEY ("ADDRESS_ID");

-- ----------------------------
-- Indexes structure for table CLASS
-- ----------------------------

-- ----------------------------
-- Triggers structure for table "SMS"."CLASS"
-- ----------------------------
CREATE OR REPLACE TRIGGER "SMS"."CLASS_CONS" BEFORE INSERT ON "SMS"."CLASS" REFERENCING OLD AS "OLD" NEW AS "NEW" ENABLE
DECLARE 
NUM NUMBER(5);
BEGIN
SELECT COUNT(*) INTO NUM FROM CLASS;
    if NUM>4
  then raise_application_error(-20001,'THIS CLASS CAN NOT BE STORED');
  end if;
END;

;

-- ----------------------------
-- Checks structure for table "SMS"."CLASS"
-- ----------------------------
ALTER TABLE "SMS"."CLASS" ADD CHECK (CLASS_ID>5 AND CLASS_ID<11);
ALTER TABLE "SMS"."CLASS" ADD CHECK ("CLASS_ID" IS NOT NULL);
ALTER TABLE "SMS"."CLASS" ADD CHECK ("CLASS_NAME" IS NOT NULL);
ALTER TABLE "SMS"."CLASS" ADD CHECK ("CLASS_ID" IS NOT NULL);
ALTER TABLE "SMS"."CLASS" ADD CHECK ("CLASS_NAME" IS NOT NULL);

-- ----------------------------
-- Primary Key structure for table "SMS"."CLASS"
-- ----------------------------
ALTER TABLE "SMS"."CLASS" ADD PRIMARY KEY ("CLASS_ID");

-- ----------------------------
-- Indexes structure for table FEES
-- ----------------------------

-- ----------------------------
-- Checks structure for table "SMS"."FEES"
-- ----------------------------
ALTER TABLE "SMS"."FEES" ADD CHECK ("BILL_NO" IS NOT NULL);
ALTER TABLE "SMS"."FEES" ADD CHECK ("STUDENT_ID" IS NOT NULL);

-- ----------------------------
-- Primary Key structure for table "SMS"."FEES"
-- ----------------------------
ALTER TABLE "SMS"."FEES" ADD PRIMARY KEY ("BILL_NO");

-- ----------------------------
-- Indexes structure for table GENSUBJECT
-- ----------------------------

-- ----------------------------
-- Uniques structure for table "SMS"."GENSUBJECT"
-- ----------------------------
ALTER TABLE "SMS"."GENSUBJECT" ADD UNIQUE ("SUBJECT_NAME");

-- ----------------------------
-- Checks structure for table "SMS"."GENSUBJECT"
-- ----------------------------
ALTER TABLE "SMS"."GENSUBJECT" ADD CHECK ("SUBJECT_ID" IS NOT NULL);
ALTER TABLE "SMS"."GENSUBJECT" ADD CHECK ("SUBJECT_NAME" IS NOT NULL);

-- ----------------------------
-- Primary Key structure for table "SMS"."GENSUBJECT"
-- ----------------------------
ALTER TABLE "SMS"."GENSUBJECT" ADD PRIMARY KEY ("SUBJECT_ID");

-- ----------------------------
-- Indexes structure for table GRADES
-- ----------------------------

-- ----------------------------
-- Uniques structure for table "SMS"."GRADES"
-- ----------------------------
ALTER TABLE "SMS"."GRADES" ADD UNIQUE ("STUDENT_ID", "CLASS_ID");

-- ----------------------------
-- Checks structure for table "SMS"."GRADES"
-- ----------------------------
ALTER TABLE "SMS"."GRADES" ADD CHECK ("GRADE_ID" IS NOT NULL);
ALTER TABLE "SMS"."GRADES" ADD CHECK ("GRADE_POINT" IS NOT NULL);
ALTER TABLE "SMS"."GRADES" ADD CHECK ("MERIT_POSITION" IS NOT NULL);
ALTER TABLE "SMS"."GRADES" ADD CHECK ("STUDENT_ID" IS NOT NULL);
ALTER TABLE "SMS"."GRADES" ADD CHECK ("GRADE_ID" IS NOT NULL);
ALTER TABLE "SMS"."GRADES" ADD CHECK ("GRADE_POINT" IS NOT NULL);
ALTER TABLE "SMS"."GRADES" ADD CHECK ("MERIT_POSITION" IS NOT NULL);
ALTER TABLE "SMS"."GRADES" ADD CHECK ("STUDENT_ID" IS NOT NULL);

-- ----------------------------
-- Primary Key structure for table "SMS"."GRADES"
-- ----------------------------
ALTER TABLE "SMS"."GRADES" ADD PRIMARY KEY ("GRADE_ID");

-- ----------------------------
-- Indexes structure for table SECTION
-- ----------------------------

-- ----------------------------
-- Uniques structure for table "SMS"."SECTION"
-- ----------------------------
ALTER TABLE "SMS"."SECTION" ADD UNIQUE ("ROOM_NO");

-- ----------------------------
-- Checks structure for table "SMS"."SECTION"
-- ----------------------------
ALTER TABLE "SMS"."SECTION" ADD CHECK ("SECTION_ID" IS NOT NULL);
ALTER TABLE "SMS"."SECTION" ADD CHECK ("CLASS_ID" IS NOT NULL);
ALTER TABLE "SMS"."SECTION" ADD CHECK ("SECTION_NAME" IS NOT NULL);

-- ----------------------------
-- Primary Key structure for table "SMS"."SECTION"
-- ----------------------------
ALTER TABLE "SMS"."SECTION" ADD PRIMARY KEY ("SECTION_ID", "CLASS_ID");

-- ----------------------------
-- Indexes structure for table STUDENTS
-- ----------------------------

-- ----------------------------
-- Triggers structure for table "SMS"."STUDENTS"
-- ----------------------------
CREATE OR REPLACE TRIGGER "SMS"."STCOUNT_TRIGGER" AFTER INSERT OR DELETE ON "SMS"."STUDENTS" REFERENCING OLD AS "OLD" NEW AS "NEW" ENABLE
DECLARE
CURSOR stcursor IS
    SELECT class_id, count(*) from students group by class_id;
  clss students.class_id%type;
  num NUMBER;

BEGIN
  
  open stcursor;
  fetch stcursor into clss, num;
  while stcursor%found loop
    update class set no_of_students=num where class_id=clss;
    fetch stcursor into clss, num;
  end loop;
  
END;

;

-- ----------------------------
-- Uniques structure for table "SMS"."STUDENTS"
-- ----------------------------
ALTER TABLE "SMS"."STUDENTS" ADD UNIQUE ("SECTION_ID", "CLASS_ID", "ROLL");

-- ----------------------------
-- Checks structure for table "SMS"."STUDENTS"
-- ----------------------------
ALTER TABLE "SMS"."STUDENTS" ADD CHECK ("FIRST_NAME" IS NOT NULL);
ALTER TABLE "SMS"."STUDENTS" ADD CHECK ("LAST_NAME" IS NOT NULL);
ALTER TABLE "SMS"."STUDENTS" ADD CHECK ("SECTION_ID" IS NOT NULL);
ALTER TABLE "SMS"."STUDENTS" ADD CHECK ("CLASS_ID" IS NOT NULL);

-- ----------------------------
-- Primary Key structure for table "SMS"."STUDENTS"
-- ----------------------------
ALTER TABLE "SMS"."STUDENTS" ADD PRIMARY KEY ("STUDENT_ID");

-- ----------------------------
-- Indexes structure for table SUBJECT
-- ----------------------------

-- ----------------------------
-- Checks structure for table "SMS"."SUBJECT"
-- ----------------------------
ALTER TABLE "SMS"."SUBJECT" ADD CHECK ("SUBJECT_ID" IS NOT NULL);
ALTER TABLE "SMS"."SUBJECT" ADD CHECK ("SECTION_ID" IS NOT NULL);
ALTER TABLE "SMS"."SUBJECT" ADD CHECK ("CLASS_ID" IS NOT NULL);
ALTER TABLE "SMS"."SUBJECT" ADD CHECK ("SUBJECT_NAME" IS NOT NULL);

-- ----------------------------
-- Primary Key structure for table "SMS"."SUBJECT"
-- ----------------------------
ALTER TABLE "SMS"."SUBJECT" ADD PRIMARY KEY ("SUBJECT_ID", "SECTION_ID", "CLASS_ID");

-- ----------------------------
-- Indexes structure for table TEACHERS
-- ----------------------------

-- ----------------------------
-- Uniques structure for table "SMS"."TEACHERS"
-- ----------------------------
ALTER TABLE "SMS"."TEACHERS" ADD UNIQUE ("FIRST_NAME", "LAST_NAME");

-- ----------------------------
-- Checks structure for table "SMS"."TEACHERS"
-- ----------------------------
ALTER TABLE "SMS"."TEACHERS" ADD CHECK ("TEACHER_ID" IS NOT NULL);
ALTER TABLE "SMS"."TEACHERS" ADD CHECK ("FIRST_NAME" IS NOT NULL);
ALTER TABLE "SMS"."TEACHERS" ADD CHECK ("LAST_NAME" IS NOT NULL);
ALTER TABLE "SMS"."TEACHERS" ADD CHECK ("JOIN_DATE" IS NOT NULL);
ALTER TABLE "SMS"."TEACHERS" ADD CHECK ("GENDER" IS NOT NULL);
ALTER TABLE "SMS"."TEACHERS" ADD CHECK ("POSITION" IS NOT NULL);
ALTER TABLE "SMS"."TEACHERS" ADD CHECK ("POS_VAL" IS NOT NULL);

-- ----------------------------
-- Primary Key structure for table "SMS"."TEACHERS"
-- ----------------------------
ALTER TABLE "SMS"."TEACHERS" ADD PRIMARY KEY ("TEACHER_ID");

-- ----------------------------
-- Indexes structure for table USERS
-- ----------------------------

-- ----------------------------
-- Checks structure for table "SMS"."USERS"
-- ----------------------------
ALTER TABLE "SMS"."USERS" ADD CHECK ("USERNAME" IS NOT NULL);
ALTER TABLE "SMS"."USERS" ADD CHECK ("PASSWORD" IS NOT NULL);

-- ----------------------------
-- Primary Key structure for table "SMS"."USERS"
-- ----------------------------
ALTER TABLE "SMS"."USERS" ADD PRIMARY KEY ("USERNAME");

-- ----------------------------
-- Foreign Key structure for table "SMS"."ADDRESSES"
-- ----------------------------
ALTER TABLE "SMS"."ADDRESSES" ADD FOREIGN KEY ("STUDENT_ID") REFERENCES "SMS"."STUDENTS" ("STUDENT_ID") ON DELETE CASCADE;
ALTER TABLE "SMS"."ADDRESSES" ADD FOREIGN KEY ("TEACHER_ID") REFERENCES "SMS"."TEACHERS" ("TEACHER_ID") ON DELETE CASCADE;

-- ----------------------------
-- Foreign Key structure for table "SMS"."FEES"
-- ----------------------------
ALTER TABLE "SMS"."FEES" ADD FOREIGN KEY ("STUDENT_ID") REFERENCES "SMS"."STUDENTS" ("STUDENT_ID") ON DELETE CASCADE;

-- ----------------------------
-- Foreign Key structure for table "SMS"."GRADES"
-- ----------------------------
ALTER TABLE "SMS"."GRADES" ADD FOREIGN KEY ("CLASS_ID") REFERENCES "SMS"."CLASS" ("CLASS_ID") ON DELETE CASCADE;
ALTER TABLE "SMS"."GRADES" ADD FOREIGN KEY ("STUDENT_ID") REFERENCES "SMS"."STUDENTS" ("STUDENT_ID") ON DELETE CASCADE;

-- ----------------------------
-- Foreign Key structure for table "SMS"."SECTION"
-- ----------------------------
ALTER TABLE "SMS"."SECTION" ADD FOREIGN KEY ("CLASS_ID") REFERENCES "SMS"."CLASS" ("CLASS_ID") ON DELETE CASCADE;

-- ----------------------------
-- Foreign Key structure for table "SMS"."STUDENTS"
-- ----------------------------
ALTER TABLE "SMS"."STUDENTS" ADD FOREIGN KEY ("SECTION_ID", "CLASS_ID") REFERENCES "SMS"."SECTION" ("SECTION_ID", "CLASS_ID") ON DELETE CASCADE;

-- ----------------------------
-- Foreign Key structure for table "SMS"."SUBJECT"
-- ----------------------------
ALTER TABLE "SMS"."SUBJECT" ADD FOREIGN KEY ("SECTION_ID", "CLASS_ID") REFERENCES "SMS"."SECTION" ("SECTION_ID", "CLASS_ID") ON DELETE CASCADE;
ALTER TABLE "SMS"."SUBJECT" ADD FOREIGN KEY ("SUBJECT_ID") REFERENCES "SMS"."GENSUBJECT" ("SUBJECT_ID") ON DELETE CASCADE;
ALTER TABLE "SMS"."SUBJECT" ADD FOREIGN KEY ("TEACHER_ID") REFERENCES "SMS"."TEACHERS" ("TEACHER_ID") ON DELETE SET NULL;
