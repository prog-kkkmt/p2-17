CREATE GENERATOR GEN_AUTOUSERS_ID;

CREATE TABLE AUTOUSERS (
    ID   T_ID /* T_ID = INTEGER NOT NULL */,
    FIO  T_FIO /* T_FIO = VARCHAR(50) */
);

CREATE OR ALTER TRIGGER AUTOUSERS_BI FOR AUTOUSERS
ACTIVE BEFORE INSERT POSITION 0
as
begin
  if (new.id is null) then
    new.id = gen_id(gen_autousers_id,1);
end;


