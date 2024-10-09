class Notification:
    def __init__(self, title, message):
        self._title = title
        self._message = message
        
    def sender(self):
        print("Estoy notificando :D")
        
        
class EmailSender(Notification):
    def __init__(self, title, message, email):
        super().__init__(title, message)
        self._email = email
    
    def sender(self):
        print("Tienes un nuevo correo")
        print(f"Para:{self._email}")
        print(f"Titulo:{self._title}")
        print(f"->{self._message}")
        
class SmsSender(Notification):
    def __init__(self, title, message, number):
        super().__init__(title, message)
        self._number = number
    
    def sender(self):
        print("Estoy vibrando")
        print(f"Para: {self._number}")
        print(f"Titulo:{self._title}")
        print(f"->{self._message}")
    
class PushSender(Notification):
    def __init__(self, title, message, device):
        super().__init__(title, message)
        self._device = device
    
    def sender(self):
        print(f"Push a {self._device}")
        print(f"Titulo:{self._title}")
        print(f"->{self._message}")
        
obj_email = EmailSender("Nuevo Correo","Lorem Ipsum Sicut Amer","cesarlunalimon@gmail.com")
obj_sms = SmsSender("Nuevo SMS","Lorem Ipsum Sicut Amer","5525256255")
obj_push = PushSender("Nueva Push","Lorem Ipsum Sicut Amer","Nokia G10")

obj_email.sender()
print("\n")
obj_sms.sender()
print("\n")
obj_push.sender()
